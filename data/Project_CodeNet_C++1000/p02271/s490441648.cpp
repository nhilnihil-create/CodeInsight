#include <stdio.h>

int func(int,int);

int n,A[100];
int main()
{
  int i,m,l;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&A[i]);
    }
  scanf("%d",&m);
  for(i=0;i<m;i++)
    {
      scanf("%d",&l);
      if(func(0,l)) printf("yes\n");
      else printf("no\n");
    }
  return 0;
}

int func(int i,int j)
{
  if(j==0) return 1;
  if(i>=n) return 0;
  if(func(i+1,j)||func(i+1,j-A[i])) return 1;
}
  