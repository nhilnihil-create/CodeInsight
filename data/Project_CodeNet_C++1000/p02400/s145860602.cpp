#include <cstdio>
#include <iostream>
using namespace std;

int main(void) {
	double r;
	double a = 3.14159265358979;
	cin >> r;
	printf("%.8lf %.8lf\n",a*r*r,2*a*r);
	return 0;
}