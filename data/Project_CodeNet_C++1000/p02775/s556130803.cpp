
// E - Payment

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int dp[1000001][2]; // dp[i][j]: 左からi桁目（j:繰り上がりフラグ）までで使用する枚数の最小値

int main() {
	string N;
	cin >> N;
	int L = N.size();
	N = " " + N;

	dp[0][1] = 1;

	for (int i=1; i<=L; i++) {
		int n = N[i] - '0';
		dp[i][0] = min(dp[i-1][0] + n, dp[i-1][1] + 10 - n);
		if (n == 9) {
			dp[i][1] = dp[i-1][1];
		} else {
			dp[i][1] = min(dp[i-1][0] + n + 1, dp[i-1][1] + 10 - (n+1));
		}
	}

	int ans = dp[L][0];

	cout << ans << endl;

	return 0;
}