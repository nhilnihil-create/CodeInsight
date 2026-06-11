#include <bits/stdc++.h>
#include <cmath>
#define _USE_MATH_DEFINES
#define EPS 1e-10
using namespace std;

int main(void) {
	double r;
	cin >> r;

	printf("%.6f %.6f\n", M_PI*r*r+EPS, M_PI*2.0*r+EPS);
	return 0;
}