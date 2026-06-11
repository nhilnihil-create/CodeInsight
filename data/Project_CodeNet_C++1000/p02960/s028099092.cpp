#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	string S;
	cin >> S;

	int len = S.size();
	vector<vector<int64_t>> dp(len + 1, vector<int64_t>(13, 0));
	dp[0][0] = 1LL;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 13; j++) {
			if (S[i] == '?') {
				for (int k = 0; k <= 9; k++) {
					dp[i + 1][(10 * j + k) % 13] += dp[i][j];
					dp[i + 1][(10 * j + k) % 13] %= MOD;
				}
			}
			else {
				int n = S[i] - '0';
				//cout << n << endl;
				dp[i + 1][(10 * j + n) % 13] += dp[i][j];
				dp[i + 1][(10 * j + n) % 13] %= MOD;
			}
		}
	}

	cout << dp[len][5] << endl;
}