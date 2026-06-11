#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using VI = vector<int>;
using PI = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<double> x(n, .0), y(n, .0);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> y[i];
	}
	double sum = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = 0; j < n; j++) {
			sum += pow(abs(x[j] - y[j]), i);
		}
		cout << setprecision(8) << fixed << pow(sum, 1. / i) << endl;
		sum = 0;
	}
	double ma = 0;
	for (int i = 0; i < n; i++) {
		ma = max(ma, abs(x[i] - y[i]));
	}
	cout << setprecision(8) << fixed << ma << endl;
	return 0;
}

