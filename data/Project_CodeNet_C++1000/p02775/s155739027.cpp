#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int dp[2][s.size()+1]; fill((int *)dp, (int *)dp + sizeof(dp)/sizeof(int), 0);
	dp[1][0] = 1;
	for (int i = 1; i <= s.size(); i++) {
		int x = s[i-1] - '0';
		dp[0][i] = min(dp[0][i-1] + x, dp[1][i-1] + (10-x));
		dp[1][i] = min(dp[0][i-1] + x + 1, dp[1][i-1] + 9 - x);
	}
	int ans = dp[0][s.size()];
	cout << ans << endl;
	return 0;
}