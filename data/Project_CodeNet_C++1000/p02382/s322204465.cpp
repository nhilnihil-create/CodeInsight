#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	int n = 0, x[100] = { 0 }, y[100] = { 0 };
	long s1 = 0, s2 = 0, s3 = 0, si = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}

	for (int i = 0; i < n; i++) {
		s1 += abs(x[i] - y[i]);
		s2 += (x[i] - y[i]) * (x[i] - y[i]);
		s3 += abs(x[i] - y[i]) * abs(x[i] - y[i]) * abs(x[i] - y[i]);
		if(si < abs(x[i] - y[i]))
			si = abs(x[i] - y[i]);
	}

	cout << setprecision(12) << setiosflags(ios::showpoint) << (double) s1 << endl
		 << sqrt(s2) << endl << cbrt(s3) << endl << (double) si << endl;

    return 0;
}