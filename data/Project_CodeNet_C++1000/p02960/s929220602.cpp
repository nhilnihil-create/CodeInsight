#include <iostream>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define MOD 1000000007

using namespace std;
using ll = long long;

ll dp[100005][13];


int main() {
	string S;
	cin >> S;

	int length = S.length();

	dp[0][0] = 1;

	for (int i = 1; i < length + 1; i++) {
		if (S[i - 1] == '?') {
			rep(j, 10) {
				rep(k, 13) {
					dp[i][(10 * k + j) % 13] += dp[i - 1][k];
					dp[i][(10 * k + j) % 13] %= MOD;
				}
			}
		}
		else {
			int x = S[i - 1] - '0';

			rep(j, 13) {
				dp[i][(10 * j + x) % 13] += dp[i - 1][j];
				dp[i][(10 * j + x) % 13] %= MOD;
			}
		}
	}

	cout << dp[length][5] << endl;

	return 0;
}