#include <bits/stdc++.h>
#define MAX (ll)(5e5 + 4)
#define MOD (ll)(1e9 + 7)
#define PI (double)(3.14159265)
#define IO ios_base :: sync_with_stdio (false), cin.tie (nullptr);

using namespace std;
using ll = long long;
using ld = long double;


int main () {
	ll n, m, v, p;
	cin >> n >> m >> v >> p;
	ll ar[n];
	for (ll i = 0; i < n; i++) {
		cin >> ar[i];
	}
	sort (ar, ar + n, greater<ll> ());
	for (ll i = 0; i < n; i++) {
	}
	ll cc = p, mi = 0;
	for (ll i = p; i < n; i++) {
		if (ar[i] == ar[p - 1]) {
			cc++;
			continue;
		}
		ll x = v - (n - i + p - 1);
		ll xx = max (0LL, (m * x - mi));
		ll ma = ar[p - 1] + xx / (i - p + 1) + (xx % (i - p + 1) > 0);
		if (ma <= ar[i] + m) {
			cc++;
		}
		mi += (ar[p - 1] - ar[i]);
	}
	cout << cc << "\n";
}
