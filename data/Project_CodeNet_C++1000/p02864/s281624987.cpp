#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

const LL inf = 1123456789012;
LL N, K;
std::vector<LL>H, nums;
std::vector<std::vector<std::vector<LL>>>memo;

LL dp(LL i, LL j, LL k)
{
	if (j < 0) return inf;
	if (i == N) return 0;
	if (memo[i][j][k] != -1) return memo[i][j][k];
	LL res1 = dp(i + 1, j, H[i]) + std::max(nums[H[i] - 1] - (k == 0 ? 0 : nums[k - 1]), 0LL);
	LL res2 = dp(i + 1, j - 1, k);
	return memo[i][j][k] = std::min(res1, res2);
}

int main()
{
	in >> N >> K;
	H.resize(N);
	rep(i, N) in >> H[i];

	nums = H;
	std::sort(nums.begin(), nums.end());
	nums.erase(std::unique(nums.begin(), nums.end()), nums.end());
	std::map<LL, LL>index;
	rep(i, nums.size()) index[nums[i]] = i + 1;
	rep(i, N) H[i] = index[H[i]];

	memo.resize(N, std::vector<std::vector<LL>>(K + 1, std::vector<LL>(N + 1, -1)));
	out << dp(0, K, 0) << std::endl;
}
