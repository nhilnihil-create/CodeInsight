#include <iostream>
#include <algorithm>
#include <cmath>
#define int long long
using namespace std;
signed main() {
	int n; double a[123], b[123];
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	for (int i = 0; i < n; i++)cin >> b[i];
	for (int p = 1; p <= 3; p++) {
		double qw = 0;
		for (int i = 0; i < n; i++)qw += pow(abs(a[i] - b[i]), p);
		printf("%.10f\n", pow(qw, (double)1 / p));
	}
	double qw = 0;
	for (int i = 0; i < n; i++)qw = max(abs(a[i] - b[i]), qw);
	printf("%.10f\n", qw);
}
