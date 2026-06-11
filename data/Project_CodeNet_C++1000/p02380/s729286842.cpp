#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int main(){
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	c = c/360.0*2.0*3.14159265358979;
	double S = a*b*sin(c)/2.0;
	double d = sqrt(a*a+b*b-2*a*b*cos(c));
	double L = a+b+d;
	double h = b*sin(c);
	printf("%lf\n%lf\n%lf\n", S, L, h);
	return 0;
}