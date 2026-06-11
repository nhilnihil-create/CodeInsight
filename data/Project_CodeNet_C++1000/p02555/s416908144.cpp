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
	long long mod = 1e9 + 7;
	int s;
	cin >> s;

	vector<long long> dp(s + 10);

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 0;
	dp[3] = 1;

	for (int i = 4; i < s + 1; i++) {
		dp[i] = dp[i - 3] + dp[i - 1];
		dp[i] %= mod;
	}
	
	cout << dp[s] << endl;
}