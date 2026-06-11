#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& d: a) cin >> d;
	sort(a.begin(), a.end());
	double res = 1.0*(a[0] + a[1])/2;
	for (int i = 2; i < n; ++i) {
		res = (res + a[i])/2;
	}
	cout << fixed << setprecision(10) << res << endl;
	return 0;
}