#include "bits/stdc++.h"
using namespace std;
long long dp[303][303];

int main() {
	int N, K;
	cin >> N >> K;
	int M = N - K;
	vector<int>H(N + 1);
	for (int i = 0; i < N; ++i) {
		cin >> H[i + 1];
	}
	for (int i = 0; i < N + 1; ++i) {
		for (int j = 0; j < M + 1; ++j) {
			dp[i][j] = 1e18;
		}
	}
	dp[0][0] = 0;

	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= M; ++j) {
			long long now = 1e18;
			for (int k = 0; k < i; ++k) {
				now = min(now, dp[k][j] + max(0, H[i] - H[k]));
			}
			dp[i][j + 1] = now;
		}
	}
	long long ans = 1e18;
	for (int i = 0; i <= N; ++i) {
		ans = min(ans, dp[i][M]);
	}
	cout << ans << endl;
	return 0;
}

