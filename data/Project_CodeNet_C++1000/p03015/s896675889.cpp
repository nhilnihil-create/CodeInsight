#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep_lr(i,l,r) for(int i=(l);i<(r);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<int, int, int> T;
constexpr int INF = INT_MAX >> 1;
constexpr ll LINF = 5000000000000000LL;
constexpr int MOD = 1000000007;

ll dp[1001000][2];

int main() {

	string s;
	cin >> s;
	int n = s.size();

	dp[0][0] = 0;
	dp[0][1] = 1;

	rep(i, n) {
		if (s[i] == '1') {
			dp[i + 1][0] = 3 * dp[i][0] + dp[i][1];
			dp[i + 1][1] = 2 * dp[i][1];
		}
		else {
			dp[i + 1][0] = 3 * dp[i][0];
			dp[i + 1][1] = dp[i][1];
		}
		dp[i + 1][0] %= MOD;
		dp[i + 1][1] %= MOD;
	}

	cout << (dp[n][0] + dp[n][1]) % MOD << endl;

}