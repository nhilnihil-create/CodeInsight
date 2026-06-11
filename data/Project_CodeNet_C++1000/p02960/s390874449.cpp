#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

ll dp[100005][13];

int main() {
	string s;
	cin >> s;
	int n = s.size();
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 13; j++) {
			if (s[i] == '?') {
				for (int d = 0; d < 10; d++) {
					dp[i+1][(j * 10 + d) % 13] += dp[i][j];
					dp[i+1][(j * 10 + d) % 13] %= MOD;
				}
			} else {
				int D = s[i] - '0';
				dp[i+1][(j * 10 + D) % 13] += dp[i][j];
				dp[i+1][(j * 10 + D) % 13] %= MOD;
			}
		}
	}
	cout << dp[n][5] << endl;
}