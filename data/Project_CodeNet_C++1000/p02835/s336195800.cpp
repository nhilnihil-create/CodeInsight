#include<stdio.h>
int main(){
  int A1,A2,A3;
  scanf("%d", &A1);
  scanf("%d", &A2);
  scanf("%d", &A3);

  if(A1+A2+A3>= 22){
    printf("bust");
  }else{
    printf("win");
  }
}