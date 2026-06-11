#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int modi = 998244353;

int main(){
	int n,s;

	cin >> n >> s;
	ll a[n];
	for(int i =0;i<n;i++){
		cin >> a[i];
	}
	ll dp[n+1][s+1];
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for(int i = 0;i<n;i++){
		for(int j =0;j<=s;j++){
			dp[i+1][j] += 2*dp[i][j];
			dp[i+1][j]%=modi;
			if(j+a[i]<=s)
			{
				dp[i+1][j+a[i]] += dp[i][j];
				dp[i+1][j+a[i]]%=modi;
			}
		}
	}

	cout << dp[n][s] << endl;
}