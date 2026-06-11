#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll a, b;
	cin >> a >> b;
	map<ll, ll> m;
	ll g = __gcd(a, b), p = g;
	repl(i, 2, sqrt(g) + 1) {
		while (p % i == 0) {
			m[i]++;
			p /= i;
		}
	}
	if (p != 1) m[p]++;
	cout << m.size() + 1 << endl;
	return 0;
}