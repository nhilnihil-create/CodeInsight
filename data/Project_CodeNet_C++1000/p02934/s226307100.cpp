#include <bits/stdc++.h>
using namespace std;


int main() {
	long double sum = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		long double x;
		cin >> x;
		sum += (long double)1 / x;
	}
	sum = (long double)1 / sum;
	cout << fixed << setprecision(10) << sum;
	return 0;
}