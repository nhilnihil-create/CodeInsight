#include <stdio.h>

main()
{
int ai,am,as,ae,bi,bm,bs,be,s,t;
scanf("%d %d %d %d %d %d %d %d",&ai,&am,&as,&ae,&bi,&bm,&bs,&be);
s = ai+am+as+ae;
t = bi+bm+bs+be;
if (s>t)	printf("%d\n",s);
else		printf("%d\n",t);
}