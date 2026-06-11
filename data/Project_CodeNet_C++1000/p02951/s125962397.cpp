#include<stdio.h>
int main(void){
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  int diff=a-b;
  if(c<=diff){
    printf("0\n");
  }else{
    printf("%d\n",c-diff); 
  }
  return 0;
}