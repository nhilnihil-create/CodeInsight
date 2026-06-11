#include<stdio.h>
int main()
{
	double a,b;
	while(scanf("%lf",&a)!=EOF)
	{
		printf("%.6lf %.6lf\n",3.141592653589*a*a,2*3.141592653589*a);
	}
	return 0;
 } 