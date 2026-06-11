#include <bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<long double> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	long double sum = (a[0] + a[1]) / 2;
	for (int i = 2; i < n; i++) {
		sum = (sum + a[i]) / 2;
	}
	cout << fixed << setprecision(10) << sum;
	return 0;
}