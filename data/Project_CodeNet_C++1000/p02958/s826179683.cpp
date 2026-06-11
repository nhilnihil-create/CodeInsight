#include <stdio.h>
int main()
{
  int n,c1=0,c2=0,k;
  scanf("%d",&n);
  int ar[n];
  for(int i=0;i<n;i++)
  {
    scanf("%d",&ar[i]);
  }
  for(int i=0;i<n;i++)
  {
    if((ar[i]==(i+1)))
    {
      c1++;
    }
 else if((ar[i]!=(i+1)))
    {
      c2++;
    }
    
  }
  if((c1==n))
  {
    printf("YES\n");
  }
  else if(c2<=2)
  {
    printf("YES\n");
  }
  else
  {
    printf("NO\n");
  }
  return 0;
  }