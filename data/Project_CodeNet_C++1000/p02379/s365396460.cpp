#include<stdio.h>
#include <math.h>

int main()
{
	double x1,y1,x2,y2;
	double ans=0,x=0,y=0;

	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	if(x1>x2) x=x1-x2;
	else if(x1<x2) x=x2-x1;
	
	if(y1>y2) y=y1-y2;
	else if(y1<y2) y=y2-y1;

	ans = (x*x)+(y*y);
	ans = sqrt(ans);
	printf("%.8lf\n",ans);

	return 0;
}