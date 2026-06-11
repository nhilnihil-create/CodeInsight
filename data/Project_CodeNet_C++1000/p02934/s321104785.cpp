#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	double a = 0;
	double b = 1;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		v[i] = x;
		b *= x;
	}
	for (int i = 0; i < n; ++i) {
		a += (b/v[i]);
	}
	double ans = b/a;
	cout << fixed << setprecision(12) << ans;
}

















