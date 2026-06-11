#include "bits/stdc++.h"
using namespace std;
double a, b, x;
bool f(double d) {
	double pi = 3.141592653589793238;
	double S;
	if (a*sin(d / 180.0 * pi) > b * cos(d / 180.0 * pi)) {
		S =(b * b / tan(d / 180.0 * pi)) / 2.0;
	}
	else {
		S = a * b - a * a * tan(d / 180.0 * pi) / 2.0;
	}
	//printf("%.10f\n", x); 
	//printf("%.10f\n", S*a);

	if (x > S*a) {
		//まだちっちゃくできる
		//こぼれすぎ
		return true;
	}
	return false;
}

int main() {
	cin >> a >>b >>x;
	double l = 0.0;
	double r = 90.0;
	for (int n = 0; n < 100; ++n) {
		double x = (l + r) / 2;
		if (f(x)) {
			r = x;
		}
		else {
			l = x;
		}
	}
	printf("%.10f\n", l);
	return 0;
}