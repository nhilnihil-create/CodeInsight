#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, K, H[310], INF = 1000000000000000;
	static long long DP[310][310][310] = {};
	H[0] = 0;
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> H[i];
	H[N + 1] = 0;
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= N + 1; j++) {
			for (int k = 0; k <= N + 1; k++) DP[i][j][k] = INF;
		}
	}
	DP[0][0][0] = 0;
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			for (int k = 0; k <= N; k++) {
				if (i != N) {
					DP[i + 1][j][k] = min(DP[i + 1][j][k], DP[i][j][k]);
				}
				DP[i + 1][j + 1][i + 1] = min(DP[i + 1][j + 1][i + 1], DP[i][j][k] + max(0LL, H[k] - H[i + 1]));
			}
		}
	}
	cout << DP[N + 1][N + 1 - K][N + 1] << endl;
}