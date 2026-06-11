// practice with Dukkha
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2000, M = 2000, MD = 1000000007;

int aa[N], bb[M], dp[N + 1][M + 1];

int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> aa[i];
	for (int j = 0; j < m; j++)
		cin >> bb[j];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			if (i == 0 && j == 0)
				dp[i][j] = 1;
			else {
				int x = 0;
				if (i > 0)
					x = (x + dp[i - 1][j]) % MD;
				if (j > 0)
					x = (x + dp[i][j - 1]) % MD;
				if (i > 0 && j > 0 && aa[i - 1] != bb[j - 1])
					x = (x - dp[i - 1][j - 1]) % MD;
				dp[i][j] = x;
			}
	int ans = dp[n][m];
	if (ans < 0)
		ans += MD;
	cout << ans << '\n';
	return 0;
}
