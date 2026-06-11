#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n;
	double d, s, c, m;
	d = s = c = m = 0;
	cin >> n;
	int* x = new int[n];
	int* y = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	for (int i = 0; i < n; i++) {
		d += abs(x[i] - y[i]);
		s += pow(abs(x[i] - y[i]), 2);
		c += pow(abs(x[i] - y[i]), 3);
		if (m < abs(x[i] - y[i])) {
			m = abs(x[i] - y[i]);
		}
	}
	cout << fixed;
	cout << setprecision(6) << d << endl << sqrt(s) << endl << cbrt(c) << endl << m << endl;
	return 0;
}
