#include<stdio.h>

int main(void)
{
  int N,K,a;
  scanf("%d%d",&N,&K);
  if(K==1){
    printf("0");
  }else{
    a=N-K;
    printf("%d",a);
  }
  
  return 0;
}