#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main() {
	double a, b, C, c;
	cin >> a >> b >> C;
	printf("%f\n", a * b * sin(C * 3.14159265 / 180.0) / 2.0);
	c = sqrt(a*a + b*b - 2.0*a*b*cos(C*3.14159265 / 180.0));
	printf("%f\n", a + b + c);
	printf("%f\n", b*sin(C*3.14159265 / 180.0));
	return 0;
}