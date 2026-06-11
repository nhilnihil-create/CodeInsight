#include <bits/stdc++.h>

#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define all(v) v.begin(), v.end()
#define ar array

#define F first
#define S second
#define sz(x) int(x.size())
using namespace std;
using ll = long long;
using pii = pair <int, int>;
using pll = pair <ll, ll>;
using ld = long double;

// const int mod = 1e9 + 7;
const int mod = 998244353;
const ll inf = 2e9;
const ll INF = 1e18;
const ld EPS = 1e-7;

const int N = 1e6 + 5;

ll a[N];

void solve () {
	int n; ll m;
	cin >> n >> m;
	ll L = 1;
	for (int i = 1 ; i <= n ; ++ i) {
		cin >> a[i];
		L = (L * a[i]) / __gcd (a[i], L);
	}
	ll k = L / 2;
	for (int i = 1 ; i <= n ; ++ i) {
		if (k % a[i] != a[i] / 2) {
			cout << 0;
			return;
		}
	}
	cout << m / L + (m % L >= k);
}

int main () {
	ios;
	int tt = 1;
	// cin >> tt;
	while (tt--) {
		solve();
		cout << "\n";
	}
}


