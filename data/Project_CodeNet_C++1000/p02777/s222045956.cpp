#include<stdio.h>
#include<string.h>
int main(){
  char S[20],T[20];
  scanf(" %s", S);
  scanf(" %s", T);

  int A, B;
  scanf("%d %d", &A, &B);
  
  char U[20];
  scanf(" %s", U);

  if(strcmp(S,U)==0){
    A= A-1;
    printf("%d %d", A, B);
  }
  else if(strcmp(T,U)==0){
    B=B-1;
    printf("%d %d", A, B);
  } else{} 
  return 0;
}