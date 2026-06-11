#include<stdio.h>

int main(){
  int x,i;
  for(i=1;i<=10000;i++){
  scanf("%d\n",&x);
    printf("Case %d: %d\n",i,x);
    if(x==0)break;}
    return 0;
}