#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include<math.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	double x[n], y[n], d1 = 0, d2 = 0, d3 = 0, de = 0;
	for (int i = 0; i < n; i++)cin >> x[i];
	for (int i = 0; i < n; i++) {
		cin >> y[i];
		double f = fabs(x[i] - y[i]);
		d1 += f;
		d2 += f * f;
		d3 += f * f * f;
		de = max(de, f);
	}
	printf("%.6f\n%.6f\n%.6f\n%.6f\n", d1, sqrt(d2), pow(d3, 1.0 / 3.0), de);
}
