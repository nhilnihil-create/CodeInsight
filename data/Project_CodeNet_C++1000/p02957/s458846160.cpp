#include <stdio.h>

int main()
{
  int a,b; scanf ("%d %d",&a,&b);
  if ((a &1) == (b&1)) printf ("%d\n",(a+b)/2);
  else puts("IMPOSSIBLE");
return 0;
}