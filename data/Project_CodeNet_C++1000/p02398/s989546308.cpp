#include <stdio.h>
int main()
{
  int a,b,c,co;
  scanf("%d %d %d",&a,&b,&c);
  if(a>b){
    a=b;
    b=a;
  }
  while(a<=b){
    if(c%a==0){
      co=co+1;
      }
      a=a+1;
    }
  printf("%d\n",co);
  return 0;
  }
    