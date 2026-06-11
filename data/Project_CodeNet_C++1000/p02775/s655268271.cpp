#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define MOD 1000000007
#define INF 1000000000

ll dp[1000001][2];

void solve_abc_e() {
	string s;
	ll ans = 0;

	cin >> s;

	rep(i, 101)rep(j, 2) {
		dp[i][j] = 0;
	}

	s = '0' + s;
	dp[0][0] = 0;
	dp[0][1] = 1;
	rep(i, s.size()) {
		ll d = s[i] - '0';
		dp[i + 1][0] = min(dp[i][0] + d, dp[i][1] + 10 - d);
		//dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + d + 1);

		dp[i + 1][1] = min(dp[i][0] + d + 1, dp[i][1] + 10 - (d + 1));
		//dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + (d + 2) % 9);
	}

	ans = dp[s.size()][0];

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc_e();

	return 0;
}