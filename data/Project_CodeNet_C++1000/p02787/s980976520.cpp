#include <iostream>
#include <algorithm>

int main() {
	int h, n;
	std::cin >> h >> n;

	int a[1010], b[1010];
	for (int i = 0; i < n; ++i)
		std::cin >> a[i] >> b[i];

	int dp[10010] = { 0 };
	dp[h] = 0;
	for (int i = 0; i < h; ++i)
		dp[i] = 1e9;

	for (int i = h; i > 0; --i) {
		for (int j = 0; j < n; ++j) {
			int pos = std::max(0, i - a[j]);
			dp[pos] = std::min(dp[pos], dp[i] + b[j]);
		}
	}

	std::cout << dp[0];
}