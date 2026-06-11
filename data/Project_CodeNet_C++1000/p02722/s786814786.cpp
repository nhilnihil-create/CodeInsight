#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll n;
	cin >> n;
	ll p = n - 1;
	map<ll, ll> mp;
	repl(i, 2, sqrt(n) + 1) {
		while (p % i == 0) {
			p /= i;
			mp[i]++;
		}
	}
	if (p != 1) mp[p]++;
	ll cnt = 1;
	for (auto m : mp) cnt *= (m.second + 1);
	cnt--;
	repl(i, 2, (ll)sqrt(n) + 1) {
		if (n % i == 0) {
			p = n;
			while (p % i == 0) p /= i;
			if (p % i == 1) cnt++;
			if (n == i * i) break;
			p = n;
			ll q = n / i;
			while (p % q == 0) p /= q;
			if (p % q == 1) cnt++;
		}
	}
	cout << cnt + 1 << endl;
	return 0;
}