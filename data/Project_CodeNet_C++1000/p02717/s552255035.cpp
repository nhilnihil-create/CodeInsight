#include<stdio.h>

int main(void)
{
  int a,b,c,temp;
  
  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&c);
  
  temp = a;
  a = b;
  b = temp;
  
  temp = a;
  a = c;
  c = temp;
  
  printf("%d %d %d\n",a,b,c);
  
  return 0;
}