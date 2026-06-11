// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int M = 10000, INF = 0x3f3f3f3f;

int dp[M + 1];

int main() {
	int m, n; cin >> m >> n;
	fill(dp, dp + m + 1, INF);
	dp[0] = 0;
	while (n--) {
		int a, b; cin >> a >> b;
		for (int x = 0; x < m; x++) {
			int y = min(x + a, m);
			dp[y] = min(dp[y], dp[x] + b);
		}
	}
	cout << dp[m] << '\n';
	return 0;
}
