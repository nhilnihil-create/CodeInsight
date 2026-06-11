#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double dis(int n, int x[], int y[], int p) {
	double absolute = 0;
	for (int i = 0; i < n; i++) {
		absolute += abs(pow((x[i] - y[i]), p));
	}

	return pow(absolute, 1.0 / p);
}

int main() {
	int n;
	cin >> n;

	int x[100];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	int y[100];
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}

	printf("%.5f\n", dis(n, x, y, 1));
	printf("%.5f\n", dis(n, x, y, 2));
	printf("%.5f\n", dis(n, x, y, 3));

	double p_inf = 0;
	for (int i = 0; i < n; i++) {
		if (p_inf < abs(x[i] - y[i])) {
			p_inf = abs(x[i] - y[i]);
		}
	}

	printf("%.5f\n", p_inf);

	return 0;
}