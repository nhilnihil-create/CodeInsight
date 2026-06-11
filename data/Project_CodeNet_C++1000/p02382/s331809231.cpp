#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n, *x, *y;

double minkowski_inf() {
	double D = 0;
	for (int i = 0; i < n; i++)
		D = max(abs(x[i] - y[i]), D);
	return D;
}

double minkowski(int p) {
	double D = 0;
	for (int i = 0; i < n; i++)
		D += pow(abs(x[i] - y[i]), p);
	D = pow(D, 1.0 / p);
	return D;
}

int main() {
	cin >> n;
	x = new int[n];
	y = new int[n];
	for (int i = 0; i < n; i++)
		cin >> x[i];
	for (int i = 0; i < n; i++)
		cin >> y[i];
	printf("%.8f\n", minkowski(1));
	printf("%.8f\n", minkowski(2));
	printf("%.8f\n", minkowski(3));
	printf("%.8f\n", minkowski_inf());
	delete[] x;
	delete[] y;
	return 0;
}