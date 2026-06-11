#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double r,area,zhou,PI;
	cin >> r;
	PI = M_PI;
	area = PI * r * r;
	zhou = PI * (r * 2);
	printf("%lf %lf",area,zhou);
	return 0;
}