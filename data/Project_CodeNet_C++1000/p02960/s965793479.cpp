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

const int mod = 1e9 + 7;
// const int mod = 998244353;
const ll inf = 2e9;
const ll INF = 1e18;
const ld EPS = 1e-7;

const int N = 1e5 + 5;

int dp[N][13];

void solve () {
	string s;
	cin >> s;
	dp[0][0] = 1;
	for (int i = 0 ; i < (int) s.size() ; ++ i) {
		char c = s[i];
		if (c != '?') {
			int u = c - '0';
			for (int j = 0 ; j < 13 ; ++ j) {
				(dp[i + 1][(j * 10 + u) % 13] += dp[i][j]) %= mod;
			}
		}
		else {
			for (int j = 0 ; j < 13 ; ++ j) {
				for (int k = 0 ; k < 10 ; ++ k) {
					(dp[i + 1][(j * 10 + k) % 13] += dp[i][j]) %= mod;
				}
			}
		}
	}
	cout << dp[s.size()][5];
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


