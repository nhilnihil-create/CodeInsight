#include <stdio.h>
int main()
{
 int n,m,flag=0;
 scanf("%d",&n);
 for(int i=1;i<=n;i++)
  {
    scanf("%d",&m);
    if(m!=i)
    flag++;
  }
 
  if(flag==0||flag==2)
    printf("YES\n");
  else
    printf("NO\n");
  
  return 0;
}