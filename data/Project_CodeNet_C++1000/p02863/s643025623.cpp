
// E - All-you-can-eat

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int dp[3001][3001]; // dp[i][j]: i番目の料理までを考慮した時に時間jまでに達成できる満足度の最大値

pair<int, int> dishes[3001];

int main() {
	int N, T;
	cin >> N >> T;

	for (int i=1; i<=N; i++) {
		int A, B;
		cin >> A >> B;
		dishes[i].first = A;  // 食べるのにかかる時間
		dishes[i].second = B; // 美味しさ
	}

	sort(dishes+1, dishes+N+1);

	for (int i=0; i<N; i++) {
		int A = dishes[i+1].first;
		int B = dishes[i+1].second;

		for (int j=0; j<=T; j++) {
			// i+1番目の料理を注文しない場合
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);

			// i+1番目の料理を注文する場合
			if (j+A <= T) {
				dp[i+1][j+A] = max(dp[i+1][j+A], dp[i][j] + B);
			}
		}
	}

	int ans = 0;
	for (int i=1; i<=N; i++) {
		ans = max(ans, dp[i-1][T-1] + dishes[i].second);
	}

	cout << ans << endl;

	// **** debug ****
	/*
	for (int i=1; i<=N; i++) {
		cout << "(" << dishes[i].first << ", " << dishes[i].second << "), ";
	}
	cout << endl;
	for (int i=0; i<=N; i++) {
		for (int j=0; j<=T; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	*/

	return 0;
}