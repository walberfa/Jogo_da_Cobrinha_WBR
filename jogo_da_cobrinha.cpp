//INTEGRANTES DA EQUIPE: WALBER FLORENCIO, SARA GUIMARÃES e IAGO LINS//

#include<windows.h>
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include <stdlib.h>
#include <time.h>

void gotoxy(int x, int y)
{
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x,y});
}

main()
{
 int x,d=2,cx[300]={1,2},cy[300]={7,7},t=1,mx,my,velo=100,nivel=1,pontos=0;
 char tecla='a'; 
 
 
 for(x=0;x<18;x++)
 { gotoxy(0,x); 
 
 printf("%c",219); //O caractere 219 na tabela ASCII imprime uma barra em pé "|" //
 }
 for(x=0;x<50;x++)
 { gotoxy(x,0); 
 printf("%c",219);
 }
 for(x=0;x<18;x++)
 { gotoxy(50,x); 
 printf("%c",219);
 }
 for(x=0;x<51;x++)
 { gotoxy(x,18); 
 printf("%c",219);
 }
 
 
 srand(time(NULL));
 mx=(rand()%49)+1;
 my=(rand()%17)+1;
 
 velo = 200;
 
 
 while(tecla!='s')
 { while(tecla!='s'&&!(tecla=kbhit()))
 
 { for(x=t;x>0;x--)
 { cx[x]=cx[x-1];
 cy[x]=cy[x-1];
 }
 
 
 if(d==0)cx[0]--;
 if(d==1)cy[0]--;
 if(d==2)cx[0]++;
 if(d==3)cy[0]++;
 
 gotoxy(cx[t],cy[t]); 
 printf(" "); 
 
 
 if(mx==cx[0]&&my==cy[0])
 { t++;
 nivel++;
 mx=(rand()%25)+1;
 my=(rand()%17)+1;
 velo-=5;
 pontos+=5;
 
 }
 gotoxy(cx[0],cy[0]);
 printf("%c",219);

 gotoxy(mx,my);
 printf("%c",3); //Na tabela ASCII o 3 imprime um coração//
 
 gotoxy(55,10);
 printf ("Pontos: %d",pontos);
 
 gotoxy(55,5);
 printf ("Nivel: %d",nivel);
 
 gotoxy(3,22);
 printf ("Alunos: Walber, Iago e Sara");

 Sleep(velo);
 
 for(x=1;x<t;x++)
 { if(cx[0]==cx[x]&&cy[0]==cy[x])tecla='s'; //Determina se a cobra encostou nela mesma//
 }
 if(cy[0]==0||cy[0]==18||cx[0]==0||cx[0]==50)tecla='s'; //Determina se a cobra bateu em uma das paredes//
 
 }

 if(tecla!='s')tecla=getch();
 if(tecla=='K')d=0;
 if(tecla=='H')d=1;
 if(tecla=='M')d=2;
 if(tecla=='P')d=3;
 
 }
 
 system("cls");
 system("pause");

 printf ("\n\n\tVOCE PERDEU\n\n");

 printf ("\n\n\tVOCE FEZ %d PONTOS",pontos);
 

 getch();
}
