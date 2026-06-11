#include <iostream>
#include <algorithm>

int main() {
	int n;
	long long cnt = 0;
	std::cin >> n;
	long long h[100000];
	long long dp[100000];
	for (int i = 0; i < n; i++) {
		std::cin >> h[i];
		dp[i] = 0;
	}
	for (int i = 1; i < n; i++) {
		dp[i] = h[i - 1] >= h[i] ? (dp[i - 1] + 1) : 0;
	}
	std::cout << *std::max_element(dp, dp + n) << "\n";
	return 0;
}