#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

ll dp[1000005][2];

int main() {
	string n;
	cin >> n;
	ll l = n.size();
	dp[0][0] = n[0] - '0';
	dp[0][1] = 11 - (n[0] - '0');
	REP(i, l - 1) {
		int d = n[i] - '0';
		dp[i][0] = min(dp[i-1][0] + d, dp[i-1][1] + d);
		dp[i][1] = min(dp[i-1][0] + 11 - d, dp[i-1][1] + 9 - d);
	}
	ll ans = min(dp[l-1][0], dp[l-1][1]);
	cout << ans << endl;
	return 0;
}

