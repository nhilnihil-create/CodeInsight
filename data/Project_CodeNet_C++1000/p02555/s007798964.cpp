#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = 1e9+100;

const int MOD = 1e9+7;

ll dp[3000] = {0};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin>>n;
	dp[0] = 1;
	for (int i = 3; i <= n; i++){
		for (int j = 3; j <= i; j++){
			dp[i] += dp[i-j];
			dp[i] %= MOD;
		}
	}
	cout<<dp[n]<<'\n';
	return 0;
}