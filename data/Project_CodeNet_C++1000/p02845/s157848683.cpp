#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int mod = 1e9 + 7;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> c(n + 1);
	c[0] = 3;
	ll ans = 1;
	rep(i, n) {
		if (c[a[i]] == 0) {
			cout << 0 << endl;
			return 0;
		}
		ans *= c[a[i]];
		ans %= mod;
		c[a[i]]--;
		c[a[i] + 1]++;
	}
	cout << ans << endl;
	return 0;
}