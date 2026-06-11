#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>

#define PI 3.1415926535
using namespace std;

int main()
{
	int a,b,arg;
	scanf("%d %d %d",&a,&b,&arg);
	double rad = (arg / 180.0) * PI;
	printf("%5lf\n",(a * b * sin(rad)) / 2);
	printf("%5lf\n",a + b + sqrt(a*a + b*b - 2*a*b*cos(rad)));
	printf("%5lf\n",b*sin(rad));
	return 0;
	
}