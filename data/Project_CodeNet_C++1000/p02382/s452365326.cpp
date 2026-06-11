#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cout << fixed << setprecision(8);
	cin >> n;
	vector<int> x(n), y(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	double res = 0;
	for (int i = 0; i < n; i++) {
		res += abs(x[i] - y[i]);
	}
	cout << res << endl;
	res = 0;
	for (int i = 0; i < n; i++) {
		res += (x[i] - y[i]) * (x[i] - y[i]);
	}
	cout << sqrt(res) << endl;
	res = 0;
	for (int i = 0; i < n; i++) {
		res += abs(x[i] - y[i]) * abs(x[i] - y[i]) * abs(x[i] - y[i]);
	}
	cout << pow(res, 1.0 / 3.0) << endl;
	int che = 0;
	for (int i = 0; i < n; i++) {
		che = max(che, abs(x[i] - y[i]));
	}
	cout << che << endl;
	return 0;
}