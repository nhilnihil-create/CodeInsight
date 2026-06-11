#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){

	double a, b, c;
	double s, l, h, rad;

	cin >> a >> b >> c ;

	rad = 3.14159265358979 * c / 180;

	s = a * b * sin(rad) / 2;
	l = a + b + sqrt(a*a + b*b - 2*a*b*cos(rad));
	h = s * 2 / a;


	printf("%.8lf\n" ,s);
	printf("%.8lf\n" ,l);
	printf("%.8lf\n" ,h);

 }