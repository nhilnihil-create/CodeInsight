#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	int n, x[1000], y[1000], i, j;
	double d;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (i = 0; i < n; i++) {
		cin >> y[i];
	}
	for (i = 0, d = 0; i < n; i++) {
		d += fabs((double)(x[i]-y[i]));
	}
	cout << fixed << setprecision(6) << d << endl;
	for (i = 0, d = 0; i < n; i++) {
		d += pow(fabs((double)(x[i]-y[i])), 2);
	}
	cout << fixed << setprecision(6) << sqrt(d) << endl;
	for (i = 0, d = 0; i < n; i++) {
		d += pow(fabs((double)(x[i]-y[i])), 3);
	}
	cout << fixed << setprecision(6) << pow(d, 1.0/3.0) << endl;
	for (i = 0, d = 0; i < n; i++) {
		d = fabs((double)(x[i]-y[i])) > d ? fabs((double)(x[i]-y[i])) : d;
	}
	cout << fixed << setprecision(6) << d << endl;
	return 0;
}