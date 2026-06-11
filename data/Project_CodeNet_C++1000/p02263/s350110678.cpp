#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isEmpty(int*);
void Push(int*,int*,int);
int Pop(int[],int*);

main(){
  int S[101];
  int top=0;
  int x,y,a,b;
  char c,s[100];


  while( scanf(" %s", s) != EOF ){
    if ( s[0] == '+' ){
	x=Pop(S,&top)+Pop(S,&top);
	Push(S,&top,x);
	
    } else if ( s[0] == '-' ){
      
      a = Pop(S,&top);
      b = Pop(S,&top);
      x=b-a; 
      Push(S,&top,x);
      
    } else if ( s[0] == '*' ){
      x=Pop(S,&top)*Pop(S,&top);
      Push(S,&top,x);
      
      
    } else {
      y=atoi(s);
      Push(S,&top,y);
    }
  }
  printf("%d\n",S[top]);
  
  return 0;
  
}

int isEmpty(int *top){
  
  if(*top==0)return 0;
  else return 1;
}

void Push(int *S,int *top,int x){
  *top+=1;
  S[*top]=x;
}

int Pop(int S[],int *top){
  if(isEmpty(top)==0) printf("underflow\n");

  else{
    *top-=1;
    return S[*top+1];
  }
}