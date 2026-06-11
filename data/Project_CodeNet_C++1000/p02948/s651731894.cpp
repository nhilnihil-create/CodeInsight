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

vector <int> add[N];

void solve () {
	int n, m;
	cin >> n >> m;
	for (int i = 1, a, b ; i <= n ; ++ i) {
		cin >> a >> b;
		add[a].push_back (b);
	}
	multiset <int> s;
	ll best = 0;
	for (int i = 1 ; i <= m ; ++ i) {
		for (int j : add[i]) s.insert (j);
		if (s.size()) {
			int x = *s.rbegin();
			s.erase (s.find (x));
			best += x;
		}
	}
	cout << best;
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


