#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll& x: a) cin >> x;
	ll res = 0;
	for (int i = 1; i < n; ++i) {
		if (a[i] < a[i-1]) {
			res += a[i-1]-a[i];
			a[i] = a[i-1];
		}
	}
	cout << res << endl;
	return 0;
}