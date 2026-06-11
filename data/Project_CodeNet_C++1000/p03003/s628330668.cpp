#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const int MOD = 1e9 + 7;

int main(){
    
    int n,m;
    cin >> n >> m;
	vector<int> s(n),t(m);
	rep(i,n) cin >> s[i];
	rep(i,m) cin >> t[i];
	
	vector<vector<ll>> dp(n+1, vector<ll>(m+1));
	rep(i,m+1) dp[0][i] = 1;
	rep(i,n+1) dp[i][0] = 1;
	
	rep(i,n){
		rep(j,m){
			dp[i+1][j+1] = (dp[i+1][j] + dp[i][j+1]) % MOD;
			if(s[i] != t[j]){
				dp[i+1][j+1] = (dp[i+1][j+1] - dp[i][j] + MOD) % MOD;
			}
		}
	}

	cout << dp[n][m] << endl;
    return 0;
    
}
