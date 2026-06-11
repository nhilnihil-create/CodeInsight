#include <bits/stdc++.h>

int main()
{
	int N, K;
	scanf("%d%d", &N, &K);
	using vi = std::vector<int64_t>;
	using vvi = std::vector<vi>;
	using vvvi = std::vector<vvi>;
	vi H(N);
	for (auto& e: H) scanf("%lld", &e);

	vi height(H);
	height.push_back(0);
	std::sort(height.begin(), height.end());
	height.erase(std::unique(height.begin(), height.end()), height.end());

	const int size_h{(int)height.size()};
	vvvi dp(N, vvi(height.size(), vi(K + 1, 1ll << 50)));
	for (int i{}; i < size_h; i++)
		if (height[i] == H.front()) dp[0][i][0] = height[i];
		else dp[0][i][1] = height[i];

	for (int n_i{1}; n_i < N; n_i++)
	{
		vvi minUp(size_h + 1, vi(K + 1, 1ll << 50)), minLow(size_h + 1, vi(K + 1, 1ll << 50));
		// 上から
		for (int h_i{size_h - 1}; h_i >= 0; h_i--)
			for (int k_i{}; k_i <= K; k_i++)
				minUp[h_i][k_i] = std::min(dp[n_i - 1][h_i][k_i], minUp[h_i + 1][k_i]);
		// 下から
		for (int k_i{}; k_i <= K; k_i++)
			minLow[0][k_i] = dp[n_i - 1][0][k_i];
		for (int h_i{1}; h_i < size_h; h_i++)
			for (int k_i{}; k_i <= K; k_i++)
				minLow[h_i][k_i] = std::min(dp[n_i - 1][h_i][k_i] - height[h_i], minLow[h_i - 1][k_i]);
		for (int h_i{}; h_i < size_h; h_i++)
		{
			if (height[h_i] == H[n_i]) // 変えない
			{
				for (int k_i{}; k_i <= K; k_i++)
					dp[n_i][h_i][k_i] = std::min(minUp[h_i][k_i], minLow[h_i][k_i] + height[h_i]);
			}
			else	// 変える
			{
				for (int k_i{1}; k_i <= K; k_i++)
					dp[n_i][h_i][k_i] = std::min(minUp[h_i][k_i - 1], minLow[h_i][k_i - 1] + height[h_i]);
			}
		}
	}
	int64_t min{1ll << 60};
	for (auto& e: dp.back())
		for (auto& f: e)
				min = std::min(min, f);
	printf("%lld\n", min);

	return 0;
}