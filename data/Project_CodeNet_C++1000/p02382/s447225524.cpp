#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main() {
	int n = 0;
	int x[100], y[100];
	cin >> n;

	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		x[i] = t;
	}
	for (int i = 0; i < n; i++) {
		cin >> t;
		y[i] = t;
	}

	double z[100];
	for (int i = 0; i < n; i++) {
		z[i] = fabs(x[i] - y[i]);
	}
	double p1 = 0;
	for (int i = 0; i < n; i++) {
		p1 += z[i];
	}

	double p2 = 0;
	for (int i = 0; i < n; i++) {
		p2 += z[i] * z[i];
	}

	double p3 = 0;
	for (int i = 0; i < n; i++) {
		p3 += z[i] * z[i]* z[i];
	}

	double pmax = z[0];
	for (int i = 1; i < n; i++) {
		if (z[i] > pmax) pmax = z[i];
	}
	
	printf("%lf\n%lf\n%lf\n%lf\n", p1, sqrt(p2), pow(p3, 1.0/3.0), pmax);

	return 0;
}
