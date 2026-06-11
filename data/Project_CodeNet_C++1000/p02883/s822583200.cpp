#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
int main() {
	ll n, k;
	cin >> n >> k;
	ll a[n], f[n];
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> f[i];
	sort(a, a + n);
	sort(f, f + n, greater<ll>());
	ll l = -1, r = 1e18 + 1;
	while (r - l > 1) {
		ll m = (l + r) / 2;
		ll p = 0;
		rep(i, n) p += max(0LL, a[i] - m / f[i]);
		if (p > k)
			l = m;
		else
			r = m;
	}
	cout << r << endl;
	return 0;
}
