// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 12, INF = 0x3f3f3f3f;

int dp[1 << N];

int main() {
	int n, m; cin >> n >> m;
	fill(dp, dp + (1 << n), INF);
	dp[0] = 0;
	while (m--) {
		int a, b; cin >> a >> b;
		int x = 0;
		while (b--) {
			int c; cin >> c, c--;
			x |= 1 << c;
		}
		for (int y = 0; y < 1 << n; y++)
			if (dp[y] != INF)
				dp[y | x] = min(dp[y | x], dp[y] + a);
	}
	int ans = dp[(1 << n) - 1];
	cout << (ans != INF ? ans : -1) << '\n';
	return 0;
}
