#include <vector>
#include <iostream>
using namespace std;
const int mod = 1000000007;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> S(N), T(M);
	for (int i = 0; i < N; ++i) cin >> S[i];
	for (int i = 0; i < M; ++i) cin >> T[i];
	vector<vector<int> > dp(N + 1, vector<int>(M + 1));
	vector<vector<int> > sum(N + 2, vector<int>(M + 2));
	dp[0][0] = 1;
	for (int i = 1; i <= N + 1; ++i) {
		for (int j = 1; j <= M + 1; ++j) {
			sum[i][j] = 1;
		}
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (S[i - 1] == T[j - 1]) {
				dp[i][j] = sum[i][j];
			}
			sum[i + 1][j + 1] = (1LL * dp[i][j] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mod) % mod;
		}
	}
	cout << sum[N + 1][M + 1] << endl;
	return 0;
}