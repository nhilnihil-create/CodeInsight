#include "bits/stdc++.h"
using namespace std;
const long long INF = 1LL << 60;
const long long mod = 1e9 + 7;
int N, M;
long long dp[100010];
int a[100010];


int main() {
	int N, M; cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> a[i];
	for (int i = 0; i <= N; i++) dp[i] = 0;
	for (int i = 0; i < M; i++) dp[a[i]] = -INF;
	dp[0] = 1;
	for (int i = 0; i <= N; i++) {
		if (dp[i] > 0) {
            dp[i] = dp[i] % mod;
			if (dp[i + 1] >= 0) dp[i + 1] += dp[i];
			if (dp[i + 2] >= 0) dp[i + 2] += dp[i];
		}
	}
	cout << dp[N] % mod << endl;

}
