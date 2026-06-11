#include<stdio.h>
int main(void)
{
  int a, b;

  scanf("%d",&a);
  scanf("%d",&b);

  if(a<=1000 && a>=-1000)
  {
    if(b<=1000 && b>=-1000)
    {

      if(a<b)
      {
        printf("a < b\n");
      }

      if(a>b)
      {
        printf("a > b\n");
      }

      if(a==b)
      {
        printf("a == b\n");
      }
    }
  }

  return 0;
}
