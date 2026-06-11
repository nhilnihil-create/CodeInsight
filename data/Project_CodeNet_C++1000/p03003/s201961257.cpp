#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1000000007;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int i;
	int n,m;
	cin>>n>>m;
	ll a[n+1],b[m+1];
	for (i = 1; i < n+1 ; i++) cin>>a[i];
	for (i = 1 ; i < m+1 ; i++) cin>>b[i];
	ll dp[n+1][m+1];
	for (i = 0; i < m+1; i++) dp[0][i] = 0;
	for (i = 0; i < n+1; i++) dp[i][0] = 0;
	for (i = 1; i < n+1 ; i++){
		for (int j = 1; j < m+1 ; j++){
			dp[i][j] = 0;
			if (a[i] == b[j]) dp[i][j] += dp[i-1][j-1]+1;
			dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
			dp[i][j] += mod;
			dp[i][j] %= mod;
			//cout<<i<<" "<<j<<" # "<<dp[i][j]<<"\n";
		}
	}
	cout<<(dp[n][m]+1)%mod<<"\n";
    return 0;
}
