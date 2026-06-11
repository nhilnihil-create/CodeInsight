#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
main () {
	double a, b, c;
	cin >> a >> b >> c;
	double t = M_PI*c/180;
	printf("%.6f\n", a*b*sin(t)/2);
	printf("%.6f\n", a+b+sqrt(a*a+b*b-2*a*b*cos(t)));
	printf("%.6f\n", b*sin(t));
}