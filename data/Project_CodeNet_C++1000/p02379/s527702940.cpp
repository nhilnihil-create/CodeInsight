#include<cstdio>
#include<math.h>

int main(){
	double a,b,c,d;
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	printf("%f\n", sqrt((c - a) * (c - a) + (d - b) * (d -b)));
	return 0;
}