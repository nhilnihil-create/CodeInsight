#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> S(N), T(M);
	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> T[i];
	}
	vector<unordered_map<int, int>> mp(M + 1);
	for (int i = M - 1; i >= 0; i--) {
		mp[i] = mp[i + 1];
		mp[i][T[i]] = i;
	}
	vector<vector<int>> dp(N + 1, vector<int>(M + 1));
	dp[0][0] = 1;
	for (int i = 0; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			(dp[i][j] += dp[i][j - 1]) %= mod;
		}
		if (i > 0) {
			for (int j = 0; j <= M; j++) {
				(dp[i][j] += dp[i - 1][j]) %= mod;
			}
		}
		if (i < N) {
			for (int j = 0; j < M; j++) {
				if (S[i] == T[j]) (dp[i + 1][j + 1] += dp[i][j]) %= mod;
			}
		}
	}
	cout << dp[N][M] << endl;
	return 0;
}
