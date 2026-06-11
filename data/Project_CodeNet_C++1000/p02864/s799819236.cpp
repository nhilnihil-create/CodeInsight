#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, K, A[1 << 18];
long long dp[309][309];

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) dp[i][j] = (1LL << 60);
	}

	dp[0][0] = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			if (dp[i][j] == (1LL << 60)) continue;
			for (int k = i + 1; k <= N + 1; k++) {
				dp[k][j + 1] = min(dp[k][j + 1], dp[i][j] + abs(A[k] - A[i]));
			}
		}
	}

	cout << dp[N + 1][N - K + 1] / 2 << endl;
	return 0;
}