#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	unsigned int n;
	double a1 = 0.0;
	double a2 = 0.0;
	double a3 = 0.0;
	double a4 = 0.0;
	vector<double> x, y;

	cin >> n;
	x.resize(n);
	y.resize(n);

	for (unsigned int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	for (unsigned int i = 0; i < n; ++i) {
		cin >> y[i];
	}
	for (unsigned int i = 0; i < n; ++i) {
		a1 += fabs(x[i] - y[i]);
		a2 += pow(x[i] - y[i], 2);
		a3 += pow(fabs(x[i] - y[i]), 3);
		a4 = max(a4, fabs(x[i]-y[i]));
	}

	cout << setprecision(10) << a1 << endl;
	cout << setprecision(10) << sqrt(a2) << endl;
	cout << setprecision(10) << cbrt(a3) << endl;
	cout << setprecision(10) << a4 << endl;
	return 0;
}

