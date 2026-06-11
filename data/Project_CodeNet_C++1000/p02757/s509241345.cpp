#include <bits/stdc++.h>

#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using ld = long double;
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

const int mod = 1e9 + 7;
// const int mod = 998244353;
const ll inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-7;

const int N = 2e5 + 66;

int cnt[N];

int binpow (ll a, int b, int mod) {
	ll res = 1;
	for (; b ; b >>= 1, (a *= a) %= mod) {
		if (b & 1) {
			(res *= a) %= mod;
		}
	}
	return res;
}

ll p[N];

ll SSS (int n, int mod, string s) {
	ll ans = 0;
	for (int i = 0 ; i < n ; ++ i) {
		int dig = s[i] - '0';
		if (dig % mod == 0) {
			ans += i + 1;
		}
	}
	return ans;
}

void solve () {
	int n, mod; string s;
	cin >> n >> mod >> s;
	if (mod == 2 || mod == 5) {
		cout << SSS (n, mod, s);
		return;
	}
	ll ans = 0;
	cnt[0]++;
	for (int i = 1 ; i <= n ; ++ i) {
		int dig = s[i - 1] - '0';
		p[i] = (p[i - 1] * 10 + dig) % mod;
		int cur = p[i] * binpow (10, n - i + 1, mod) % mod;
		ans += cnt[cur];
		cnt[cur]++;
	}
	cout << ans;
}

int main () {
	ios;
	// double start_time = clock();
	// cout << fixed << setprecision (10);
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
		cout << "\n";
	}
	// cerr << (clock() - start_time) / CLOCKS_PER_SEC;
}
