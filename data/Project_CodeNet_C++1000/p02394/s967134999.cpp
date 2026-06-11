#include <stdio.h>

main()
{
int W,H,x,y,r;
int xl,xr,yl,yr;

scanf("%d %d %d %d %d",&W,&H,&x,&y,&r);

xl=r;
xr=W-r;
yl=r;
yr=H-r;

if((xl<=x) && (x<=xr) && (yl<=y) && (y<=yr)) printf("Yes\n");
else printf("No\n");
}