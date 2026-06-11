#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3005, MOD = 998244353;
int dp[N][N], a[N], n, s;
main(){
	dp[0][0] = 1;
	cin >> n >> s;
	for(int i = 1; i <= n; ++i)cin >> a[i];
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= s; ++j){
			if(a[i] <= j){
				dp[i][j] = dp[i - 1][j - a[i]];
			}
			dp[i][j] += dp[i - 1][j] * 2;
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n][s] << endl;
}