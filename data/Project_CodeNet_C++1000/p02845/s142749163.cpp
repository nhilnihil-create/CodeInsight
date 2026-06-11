#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9+7;
const int N = 100001;

int main () {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	ll ans = 1; vector<int> c(4,0);
	for (int i = 0; i < n; ++i) {
		ll tmp = 0, x = 3;
		for (int j = 0; j < 3; ++j) {
			if (a[i] == c[j]) {
				tmp++; x = j;
			}
		}
		(ans *= tmp) %= MOD;
		c[x]++;
	}
	cout << ans << endl;

	return 0;
}