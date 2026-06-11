#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<double> x(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	vector<double> y(n);
	for (int j = 0; j < n; ++j) {
		cin >> y[j];
	}
	double d1 = 0;
	double d2 = 0;
	double d3 = 0;
	double dinf = -1;
	for (int k = 0; k < n; ++k) {
		double diffe = sqrt(pow((x[k] - y[k]), 2));
		d1 += diffe;
		d2 += pow(diffe, 2);
		d3 += pow(diffe, 3);
		if (dinf < diffe) {
			dinf = diffe;
		}
	}
	printf("%.5f\n", d1);
	printf("%.5f\n", sqrt(d2));
	printf("%.5f\n", pow(d3, 1.0 / 3.0));
	printf("%.5f\n", dinf);
	return 0;
}