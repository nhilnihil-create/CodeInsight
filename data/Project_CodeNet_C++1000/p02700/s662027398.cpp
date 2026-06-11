#include<stdio.h>

int main(void)
{
  int a,b,c,d;
  int count = 1;
  
  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&c);
  scanf("%d",&d);
  
  do{
    if(count > 0)
      c = c - b;
    else
      a = a - d;
    count = -count;
  }while(a > 0 && c > 0);
  
  if(a <= 0)
    printf("No");
  else
    printf("Yes");
  
  return 0;
}