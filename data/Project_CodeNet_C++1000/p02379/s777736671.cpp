#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<cctype>
#include<string.h>

int main()
{
	double x1 = 0.0, x2 = 0.0, y1 = 0.0, y2 = 0.0;
	scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
	printf("%f\n", sqrt((x1 - x2)*(x1-x2)+ (y1 - y2)*(y1-y2)));
	return 0;
}