#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

void chmax(Int& a, Int b) { if (a < b) { a = b; } };

int main() {
	int N;
	cin >> N;
	vector<pair<Int, Int>> ai(N);
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		ai[i] = { a, i };
	}

	sort(ai.rbegin(), ai.rend());
	vector<vector<Int>> dp(N + 1, vector<Int>(N + 1, 0));
	for (int i = 0; i < N; ++i) {
		Int val = ai[i].first, idx = ai[i].second;
		for (int l = 0; l <= i + 1; ++l) {
			int r = i + 1 - l;
			if (l > 0) { 
				chmax(dp[l][r], dp[l - 1][r] + val * abs(idx - (l - 1)));
			}
			if (r > 0) {
				chmax(dp[l][r], dp[l][r - 1] + val * abs(idx - (N - r)));
			}
		}
	}

	Int ans = 0;
	for (int i = 0; i <= N; ++i) {
		chmax(ans, dp[i][N - i]);
	}
	cout << ans << endl;

	return 0;
}
