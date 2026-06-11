#include<stdio.h>
#include<math.h>
int main()
{
	double x,y,x1,x2,y1,y2,d,distance;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	x=x2-x1;
	x=pow(x,2.0);
	y=y2-y1;
	y=pow(y,2.0);
	d=x+y;
	distance=sqrt(d);
	printf("%lf\n",distance);
	return 0;

	
}