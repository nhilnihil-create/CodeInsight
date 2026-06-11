#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

int main() {
	string S; cin >> S;
	vector<vector<int>> dp(S.size()+1, vector<int>(13, 0));
	dp[0][0] = 1;
	int keta = 1;
	rep(i, S.size()) {
		if (S[S.size() - i - 1] == '?') {
			rep(j, 10) {
				int num = j * keta;
				num %= 13;
				rep(k, 13) {
					dp[i + 1][(num + k) % 13] += dp[i][k];
				}
				rep(k, 13)dp[i + 1][k] %= MOD;
			}
		}
		else {
			int num = S[S.size() - i - 1] - '0';
			//cout << num << endl;
			num = (num * keta) % 13;
			rep(k, 13) {
				dp[i + 1][(num + k) % 13] += dp[i][k];
			}
		}
		rep(j, 13)dp[i + 1][j] %= MOD;
		keta *= 10;
		keta %= 13;
	}

	cout << dp[S.size()][5];
}