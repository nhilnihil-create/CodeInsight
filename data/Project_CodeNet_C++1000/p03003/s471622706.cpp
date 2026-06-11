#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define int long long
int MOD = 1000000007;
signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(M);
	int res = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> B[i];
	}
	vector<vector<int> > dp(N + 1, vector<int>(M + 1, 0));


	for (int i = 0; i <= N; i++) {
		dp[i][0] = 1;
	}
	for (int i = 0; i <= M; i++) {
		dp[0][i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			if (A[i - 1] != B[j - 1]) {
				dp[i][j] -= dp[i - 1][j - 1];
			}
			dp[i][j] = (dp[i][j] + MOD) % MOD;
		}
	}
	cout << dp[N][M] << endl;
}
