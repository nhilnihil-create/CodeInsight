#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

typedef long long ll;

int main(){
	const int MOD = 1e9+7;
	string L;
	cin >> L;
	int n = L.size();
	vector<vector<int>> dp(100005, vector<int>(2));
	dp[0][0] = 1;

	rep(i,n){
		// a+b = 0
		if(L[i] == '0'){
			dp[i+1][0] = dp[i][0];
			dp[i+1][1] = dp[i][1];
		}else{
			dp[i+1][1] = (dp[i][0] + dp[i][1] ) % MOD;
		}

		// a+b = 1
		if(L[i] == '0'){
			dp[i+1][1] += (dp[i][1]*2%MOD);
			dp[i+1][1] %= MOD;
		}else{
			dp[i+1][0] += dp[i][0]*2%MOD;
			dp[i+1][1] += dp[i][1]*2%MOD;
			dp[i+1][0] %= MOD;
			dp[i+1][1] %= MOD;
		}
	}

	int ans = (dp[n][0] + dp[n][1]) % MOD;
	cout << ans << endl;
	return 0;
}