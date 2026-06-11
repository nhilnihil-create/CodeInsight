#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;

const int MOD = 998244353;

int add(int x, int y) {return (x+y) % MOD;}
int mul(int x, int y) {return (x*1ll*y) % MOD;}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, s;
	cin >> n >> s;
	int a[n];
	for (int i=0; i<n; i++) cin >> a[i];
	int dp[n+1][s+1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int i=0; i<n; i++) {
		for (int j=0; j<=s; j++) {
			dp[i+1][j] = add(dp[i+1][j], mul(2, dp[i][j]));
			if (j + a[i] <= s) dp[i+1][j + a[i]] = add(dp[i+1][j + a[i]], dp[i][j]);
		}
	}
	cout << dp[n][s];
}