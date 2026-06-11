// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 3000, T = 3000;

int aa[N], bb[N], dp[N][T], dq[N][T];

int main() {
	int n, t; cin >> n >> t;
	for (int i = 0; i < n; i++)
		cin >> aa[i] >> bb[i];
	for (int i = 0; i + 1 < n; i++) {
		int a = aa[i], b = bb[i];
		for (int x = t - 1; x >= 0; x--) {
			dp[i + 1][x] = dp[i][x];
			if (x + a < t)
				dp[i + 1][x + a] = max(dp[i + 1][x + a], dp[i][x] + b);
		}
	}
	for (int i = 0; i + 1 < n; i++) {
		int a = aa[n - 1 - i], b = bb[n - 1 - i];
		for (int x = t - 1; x >= 0; x--) {
			dq[i + 1][x] = dq[i][x];
			if (x + a < t)
				dq[i + 1][x + a] = max(dq[i + 1][x + a], dq[i][x] + b);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int p = i, q = n - 1 - i;
		for (int x = t - 1, y = 0, z = 0; x >= 0; x--, y++)
			ans = max(ans, dp[p][x] + bb[i] + (z = max(z, dq[q][y])));
	}
	cout << ans << '\n';
	return 0;
}
