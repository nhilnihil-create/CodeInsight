#include <bits/stdc++.h>

using namespace std;

double solve(int *z, int p, int n) {
	double d;

	d = 0;
	for (int i = 0; i < n; ++i) {
		d += pow(z[i], p);
	}
	return pow(d, 1.0 / p);
}

int main() {
	int n;
	int x[100], y[100], z[100];
	double d[4];

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> y[i];
		z[i] = abs(x[i] - y[i]);
	}
	d[3] = *max_element(z, z + n);
	for (int i = 0; i < 3; ++i) {
		d[i] = solve(z, i + 1, n);
	}

	for (int i = 0; i < 4; ++i) {
		cout << fixed << setprecision(6) << d[i] << endl;
	}

	return 0;
}
