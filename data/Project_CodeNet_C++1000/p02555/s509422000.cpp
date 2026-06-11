#include <bits/stdc++.h>
#define ll long long 
using namespace std;

const int m = 1e9 + 7;

ll int count(int n) {
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 3; j <= n; j++) {
			if(i - j >= 0)
				dp[i] = (dp[i] + dp[i - j]) % m;
				dp[i] %= m;
		}
	}
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	ll int ans = count(n) % m;
	cout << ans;
}