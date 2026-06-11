#include <iostream>
#include <cstdio>

#define PI 3.14159265358979323

using namespace std;

int main() {
	double r;
	cin >> r;
	double s = PI * r * r;
	double l = 2 * PI * r;
	printf("%.8lf %.8lf\n", s, l);
	return 0;
}