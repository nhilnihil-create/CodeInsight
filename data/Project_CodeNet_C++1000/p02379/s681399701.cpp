#include<stdio.h>
#include<math.h>
int main()
{
	double x1,x2,y1,y2;
	double distance;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
    double x=pow(x1-x2,2);
    double y=pow(y1-y2,2);
    distance=sqrt(x+y);
    printf("%.8f",distance);
    return 0;
	
}