#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;

int main(void) {
	int n, i, dp[1000003][2] = {};
	string s;

	cin >> s;

	n = s.size();

	dp[0][0] = 0;
	dp[0][1] = 1;
	for (i = 1; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][0] + s[i - 1] - '0', dp[i - 1][1] + 10 - (s[i - 1] - '0'));
		dp[i][1] = min(dp[i - 1][0] + s[i - 1] - '0' + 1, dp[i - 1][1] + 9 - (s[i - 1] - '0'));
	}

	cout << dp[n][0] << endl;

	return 0;
}