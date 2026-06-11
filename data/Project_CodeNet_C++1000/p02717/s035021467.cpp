#include <stdio.h>
int main(void){
  int X, Y, Z;
  int a, b;
  
  scanf("%d %d %d",&X,&Y,&Z);
  
  a=X;
  X=Y;
  Y=a;
  
  b=X;
  X=Z;
  Z=b;
  
  printf("%d %d %d", X, Y, Z);
  
  return 0;
}