#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, x[100], y[100];
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> x[i];
	for (int i = 0; i < n; ++i) cin >> y[i];
	long double sum = 0;

	for (int i = 0; i < n; ++i) sum += abs(x[i] - y[i]);
	cout << sum << endl;
	sum = 0;

	for (int i = 0; i < n; ++i) sum += (x[i] - y[i]) * (x[i] - y[i]);
	cout << setprecision(10) << sqrt(sum) << endl;
	sum = 0;

	for (int i = 0; i < n; ++i) sum += abs((x[i] - y[i]) * (x[i] - y[i]) * (x[i] - y[i]));
	cout << setprecision(10) << cbrt(sum) << endl;
	sum = 0;

	for (int i = 0; i < n; ++i) sum = max(sum, (long double)abs(x[i] - y[i]));
	cout << sum << endl;
	return 0;
}