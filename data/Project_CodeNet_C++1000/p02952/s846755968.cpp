#include <stdio.h>
int main()
{
  int N=0,m=0,c=0,count=0;
  scanf("%d",&N);
  for(int i=1;i<=N;i++)
  {
   
    for(m=i;m!=0;++c)
    {
      m=m/10;
    }
    if(c%2!=0)
    {
      count++;
    }
    c=0;
  }
  printf("%d ",count);
  return 0;
  }
 