#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	double r;

	scanf("%lf", &r);

	printf("%lf %lf\n", r * r * M_PI, 2.0 * M_PI * r);
	
	return (0);
}