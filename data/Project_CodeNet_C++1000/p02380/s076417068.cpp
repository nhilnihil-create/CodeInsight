#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int main(){
	double deg;
	double PI = acos(-1);
	double rad;
	
	double a, b;
	cin >> a >> b >> deg;
	rad = PI / 180 * deg;
	printf("%.8lf\n", a * b * sin(rad) / 2);
	printf("%.8lf\n", a + b + sqrt(a*a + b*b - 2*a*b*cos(rad)));
	printf("%.8lf\n", b * sin(rad));
		
	return 0;
}