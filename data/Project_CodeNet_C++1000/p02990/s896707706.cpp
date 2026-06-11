#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
long long dp[2005][2005];

int main(){
	int n,k;
	cin >> n >> k;

	dp[0][0] = 1;
	for (int i=1; i<=n; i++){
		for (int j=0; j<=i; j++){
			if(j==0) dp[i][j] = 1;
			else dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%MOD;
		}
	}
				
	for (int i=1; i<=k; i++){
		cout << (dp[n-k+1][i]*dp[k-1][i-1])%MOD << endl;
	}

	return 0;
}