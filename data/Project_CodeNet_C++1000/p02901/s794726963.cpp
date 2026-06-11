#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;
const int INF = 1 << 30;
const long long LINF = 1LL << 60;
const long long MOD = 1000000000 + 7;
const double PI = acos(-1);

int main() {
	int N, M; cin >> N >> M;
	vector<vector<int>> keys(M);
	rep(i, M) {
		int a, b; cin >> a >> b;
		keys[i].push_back(a);
		rep(j, b) {
			int c; cin >> c;
			keys[i].push_back(c);
		}
	}
	vector<vector<int>> dp(M + 1, vector<int>((1 << N) + 1, INF));
	dp[0][0] = 0;

	rep(i, M) {
		int num = 0;
		rep(j, keys[i].size() - 1) {
			num += pow(2, keys[i][j + 1] - 1);
		}
		rep(j, 1 << N) {
			// 既に[i+1][j]に値が入っていることがあるので、自身と比較する
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			dp[i + 1][j | num] = min(dp[i + 1][j | num], dp[i][j] + keys[i][0]);
		}
	}
	int ans = dp[M][(1 << N) - 1];
	if (ans < INF)cout << dp[M][(1 << N) - 1];
	else cout << -1;
}
