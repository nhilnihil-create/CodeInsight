#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	long long inf = 1e18;
	long long mod = 1e9 + 7;

	int n,m;
	cin >> n >> m;

	vector<long long> dp(n + 1, -1);
	dp[0] = 1;

	rep(i, m) {
		int x;
		cin >> x;
		dp[x] = 0;
	}

	for (int i = 1; i < n + 1; i++) {
		if (dp[i] == 0) {
			continue;
		}
		if (i == 1) {
			dp[i] = dp[i - 1];
			continue;
		}
		dp[i] = dp[i - 1] + dp[i - 2];
		if (dp[i] > mod)
			dp[i] %= mod;
	}
	//dp確認用
	/*
	rep(i, n + 1) {
		cout << dp[i] << endl;
	}
	*/


	cout << dp[n] << endl;
	return 0;
}