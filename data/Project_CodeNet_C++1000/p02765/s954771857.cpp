#include<stdio.h>
int main(void)
{
  int n,r;
  
  
  scanf("%d",&n);
  scanf("%d",&r);
  
  if(n<10)
    printf("%d",r+100*(10-n));
  else
    printf("%d",r);
  return 0;
  
}