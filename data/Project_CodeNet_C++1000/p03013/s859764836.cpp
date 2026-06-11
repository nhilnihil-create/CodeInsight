#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> a(n+1,1);
	int s;

	for (int i=0; i<m; i++){
		cin >> s;
		a[s] = 0;
	}

	vector<long long> dp(n+10,0);
	dp[0] = 1;
	for (int i=0; i<n; i++){
		if (a[i+1]){
			dp[i+1] += dp[i];
			dp[i+1] %= MOD;
		}
		if (a[i+2]){
			dp[i+2] += dp[i];
			dp[i+2] %= MOD;
		}
	}

	cout << dp[n] << endl;

	return 0;
}