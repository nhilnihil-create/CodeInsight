#include<stdio.h>
int main(){
  int A,B,C;
  scanf("%d",&A);
  scanf("%d",&B);
  scanf("%d",&C);
  if(A==B && A!=C){
    printf("Yes");
  }
  else if(A==C && A!=B){
   printf("Yes");
  }
  else if(B==C && B!=A){
    printf("Yes");
  }
  else if(A==B && B==C){
    printf("No");
  }
  else if(A!=B && B!=C){
    printf("No");
  }
  return 0;
 }