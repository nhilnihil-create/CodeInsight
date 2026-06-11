#include <stdio.h>
int main()
{
int c = 0;
while(true)
{
int n;
scanf("%d",&n);
if(0 == n)
break;
++c;
printf("Case %d: %d\n", c, n);
}
return 0;
}