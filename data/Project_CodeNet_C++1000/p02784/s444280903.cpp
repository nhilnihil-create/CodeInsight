#include <stdio.h>
int main()
{
  int x,y,i,sum=0;
  scanf("%d%d",&x,&y);
  int ar[y];
  for(int i=0;i<y;i++)
  {
    scanf("%d",&ar[i]);
    sum=sum+ar[i];
    }
    if(x<=sum)
    {
      printf("Yes\n");
    }
    else
    {
      printf("No\n");
    }
   return 0;
   }