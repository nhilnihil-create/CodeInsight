#include <iostream>
#include <cstdio>
using namespace std;
#define PI 3.14159265359

int main(void) {
	double r;
	cin >> r;
	printf("%lf %lf \n", r * r * PI, (r + r) * PI);
	return 0;
}