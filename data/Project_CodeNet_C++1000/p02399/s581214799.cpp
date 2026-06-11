#include<stdio.h>

int main(){
  int a,b;
  double f;
  scanf("%d %d",&a,&b);
  printf("%d ",a/b);
  printf("%d ",a%b);
  printf("%lf\n",(double)a/(double)b);
}