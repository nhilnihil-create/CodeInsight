#include <bits/stdc++.h>
using namespace std;
const int M = 1e9 + 7;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int s; cin >> s;
	vector<int> dp(s + 1, 1);
	dp[1] = dp[2] = 0;
	for (int i = 6; i <= s; ++i) {
		for (int j = 3; j <= i - 3; ++j) {
			dp[i] = ((long long) dp[i] + dp[j]) % M;
		}
	}
	cout << dp[s] << endl;
	return 0;
}