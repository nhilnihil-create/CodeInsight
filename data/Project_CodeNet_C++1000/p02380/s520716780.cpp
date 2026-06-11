#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int a, b;
	double c;
	double pi = 3.1415926535;
	cin >> a >> b >> c;
	c = c*pi/180;
	printf("%.8lf\n%.8lf\n%.8lf\n", a*b*sin(c)/2.0, a + b + sqrt(a*a + b*b - 2*a*b*cos(c)), b*sin(c));
	return 0;
}