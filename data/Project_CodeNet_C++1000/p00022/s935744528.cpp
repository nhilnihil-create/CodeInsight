#include<iostream>
#include<vector>

int main() {
	int n;
	while (std::cin >> n) {
		if (n == 0) break;
		std::vector<int> a;
		for (int i = 0; i < n; ++i) {
			int ai;
			std::cin >> ai;
			a.push_back(ai);
		}
		// ここをかく
		int dp[6000], max;
		dp[0] = max = a[0];
		for (int i = 1; i < n; i++) {
			if (dp[i - 1] >= 0) {
				dp[i] = dp[i - 1] + a[i];
			}
			else {
				dp[i] = a[i];
			}
			max = max > dp[i] ? max : dp[i];
		}

		std::cout << max << std::endl;
	}

	return 0;
}
