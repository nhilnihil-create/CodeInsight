#include <bits/stdc++.h>

using namespace std;

int mod = 1e9+7;

long long int solve(int s, vector<int>& dp) {

	if(dp[s] != -1) return dp[s];

	if(s < 3) return 0;

	dp[s] = 1;

	for(int i=3; i<s; i++) {

		dp[s] += solve(s-i, dp);
		dp[s] %= mod;
	}

	return dp[s];
}

int main() {

	int s;
	cin>>s;

	vector<int> dp(s+1, -1);
	
	int ans = solve(s, dp);

	cout<<ans<<endl;
	
	return 0;
}