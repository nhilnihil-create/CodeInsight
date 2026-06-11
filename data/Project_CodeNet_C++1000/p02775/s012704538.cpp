#include <iostream>
using namespace std;

const int mxN = 1e6 + 5;
long long dp[mxN][2];

int main() {
	string s;
	cin >> s;
	int n = s.size();
	dp[0][1] = 1;
	for(int i = 0; i < n; ++i) {
		int cur = s[i] - '0';
		dp[i + 1][0] = min(dp[i][0] + cur, dp[i][1] + 10 - cur);
		dp[i + 1][1] = min(dp[i][0] + cur + 1, dp[i][1] + 10 - cur - 1);
	}
	cout << dp[n][0];
}
