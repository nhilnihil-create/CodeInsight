#include<stdio.h>

int main(void)
{
  int n[33]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 
             5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  int a;
  
  scanf("%d",&a);
  printf("%d",n[a-1]);
  return 0;
}