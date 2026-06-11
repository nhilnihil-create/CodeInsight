#include<stdio.h>
int main(void)
{
  int x,y,z;
  int a;
  
  scanf("%d",&x); 
  scanf("%d",&y); 
  scanf("%d",&z);
  
  a=x;
  x=y;
  y=a;
  
  a=z;
  z=x;
  x=a;
  
  printf("%d ",x);
  printf("%d ",y);
  printf("%d ",z);
  
  return 0;
}