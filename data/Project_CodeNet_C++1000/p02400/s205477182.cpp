#include<stdio.h>
#include<cmath>
using namespace std;
  
int main()
{
	double r;
	scanf("%lf", &r);
	
	double S = r * r * M_PI;
	double L = 2 * r * M_PI;
	
	printf("%.6lf\n%.6lf\n" , S ,L);
	return 0;
}