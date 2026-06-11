#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int main(){
	int n,s;
	cin >> n >> s;
	vector<long long> dp(s+1);
	dp[0] = 1;
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		for(int j = s; j >= 0; j--){
			dp[j] += dp[j];
			if(j - x >= 0)
			 dp[j] += dp[j-x];
			dp[j]%=MOD;
		}
	}
	cout << dp[s] << "\n";
	return 0;
}
