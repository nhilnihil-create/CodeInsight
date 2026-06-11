#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main() {
	int n, x[100], y[100], d[100];
	double D1, D2, D3, Di;
	D1 = 0;
	D2 = 0;
	D3 = 0;
	Di = 0;

	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> x[i];
	for (int i = 0;i < n;i++) {
		cin >> y[i];
		d[i] = x[i] - y[i];
		if (d[i] < 0)
			d[i] = -1 * d[i];
		D1 += d[i];
		D2 += d[i] * d[i];
		D3 += d[i] * d[i] * d[i];
		if (Di < d[i])
			Di = d[i];
	}
	D2 = sqrt(D2);
	D3 = pow(D3, 1.0/3.0);

	printf("%f\n%f\n%f\n%f\n", D1, D2, D3, Di);

	return 0;
}