#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n), c(n);
	rep(i, n) {
		cin >> a[i];
		a[i]--;
		c[a[i]]++;
	}
	ll ans = 0;
	rep (i, n) {
		ll sel;
		if (c[i] % 2) sel = c[i] * ((c[i] - 1) / 2);
		else sel = (c[i] / 2) * (c[i] - 1);
		ans += sel;
	}
	rep (i, n) cout << ans - c[a[i]] + 1 << endl;
	return 0;
}
