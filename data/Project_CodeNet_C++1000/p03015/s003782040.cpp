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
ll dp[2][100005];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string l;
	cin >> l;
	int n = l.size();
	dp[0][0] = 2;
	dp[1][0] = 1;
	rep(i, n - 1) {
		if (l[i + 1] == '1') {
			dp[0][i + 1] = dp[0][i] * 2 % MOD;
			dp[1][i + 1] = (dp[1][i] * 3 + dp[0][i]) % MOD;
		} else {
			dp[0][i + 1] = dp[0][i];
			dp[1][i + 1] = dp[1][i] * 3 % MOD;
		}
	}
	cout << (dp[0][n - 1] + dp[1][n - 1]) % MOD << endl;
	return 0;
}