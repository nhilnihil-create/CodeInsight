#include "bits/stdc++.h"
using namespace std;
int dp[3005][3005];
int main() {
	int N,T;
	cin >> N >> T;
	vector<pair<int, int>>P;
	for (int n = 0;n<N;++n) {
		int x, y;
		cin >> x >> y;
		P.emplace_back(make_pair(x, y));
	}
	sort(P.begin(),P.end());
	int ans = 0;
	for (int i = 0;i < N;++i) {
		for (int j = 0; j < T;++j) {
			dp[i + 1][j] = max(dp[i + 1][j],dp[i][j]);
			int nj = j + P[i].first;
			if (nj < T) {
				dp[i + 1][nj] = max(dp[i + 1][nj], dp[i][j] + P[i].second);
			}
		}
		int now = dp[i][T - 1] + P[i].second;
		ans = max(ans, now);
	}
	cout << ans <<endl;
	return 0;
}