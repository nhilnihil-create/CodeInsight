#include<stdio.h>
 
int main(void)
{
  int x,y,z,n;
  scanf("%d %d %d",&x,&y,&z);
  n=x;
  x=y;
  y=n;
  n=x;
  x=z;
  z=n;
  printf("%d %d %d",x,y,z);
  return 0;
}