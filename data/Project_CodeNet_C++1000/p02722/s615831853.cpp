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
// const ld PI = acos(-1.0);

const int N = 1e6 + 66;

int _div (ll x) {
	int res = 0;
	for (ll i = 1 ; i * i <= x ; ++ i) {
		if (x % i == 0) {
			res++;
			res += i * i != x;
		}
	}
	return res;
}

bool okay (ll x, ll y) {
	while (y % x == 0) y /= x;
	y %= x;
	// cout << x << " " << y << "\n";
	// if (y == 1) cout << x << " is okay\n";
	return y == 1;
}

void solve () {
	ll n;
	cin >> n;
	ll res = _div (n - 1) - 1; // because of 1
	for (ll i = 1 ; i * i <= n ; ++ i) {
		if (n % i == 0) {
			if (i != 1)
				res += okay (i, n);
			if (i * i != n)
				res += okay (n / i, n);
		}
	}
	cout << res;
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