#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <functional>
#include <cmath>
#define REP(i,n) for(lint i{}, i##_len=(n); i<i##_len; ++i)
#define DOUBLE_LOOP(i, h, j, w) for(lint i{}; i < (lint)(h); ++i)for(lint j{}; j < (lint)(w); ++j)
#define DOUBLE_LOOP2(i, j, n) for(lint i{}; i < (lint)(n - 1); ++i)for(lint j{i + 1}; j < (lint)(n); ++j)
#define SZ(x) ((lint)(x).size())
using lint = long long; lint N, M, H, W;
using namespace std;
const long long INF{ 1LL << 60 };
const long double PI{ 3.1415926535897932 };
const long long NUM97{ 1000000007 };
template<class T> inline bool chmax(T& x, T y) { if (x < y) { x = y; return 1; } return 0; }
template<class T> inline bool chmin(T& x, T y) { if (x > y) { x = y; return 1; } return 0; }
std::vector<std::string> field;
std::vector<std::vector<bool>> seen(H, std::vector<bool>(W));
const std::vector<int> dx { 1, 0, -1, 0 };
const std::vector<int> dy { 0, 1, 0, -1 };
lint DP_1_Memoization(lint i, std::vector<lint> dp, std::vector<lint> h) {
	if (dp[i] < INF) { return dp[i]; } if (i == 0) { return 0; }
	lint ans{ INF }; chmin(ans, DP_1_Memoization(i - 1, dp, h) + std::abs(h[i] - h[i - 1]));
	if (i > 1) { chmin(ans, DP_1_Memoization(i - 2, dp, h) + std::abs(h[i] - h[i - 2])); }
	return dp[i] = ans;} // memoization
void DP_1(){lint n;  std::cin >> n;
	std::vector<lint> dp; dp.resize(N);  for (auto& r : dp) r = INF;
	std::vector<lint> h; h.resize(n); for (auto& r : h) std::cin >> r;
	dp[0] = 0; for (int i = 1; i < N; ++i) {
		chmin(dp[i], dp[i - 1] + std::abs(h[i] - h[i - 1]));
		if (i > 1) { chmin(dp[i], dp[i - 2] + std::abs(h[i] - h[i - 2])); }}
	std::cout << dp[N - 1] << DP_1_Memoization(N - 1, dp, h) << std::endl;}

int main() { lint N, M; std::cin >> N >> M;
	std::vector<bool> issafe(N + 1, true);
	std::vector<lint> dp(N + 1, 0);
	for (int i = 0; i < M; ++i) { int a; cin >> a; issafe[a] = false; }
	dp[0] = 1; if (issafe[1] == true) dp[1] = 1;
	for (int i = 2; i <= N; ++i) {
		if (issafe[i - 1]) dp[i] += dp[i - 1];
		if (issafe[i - 2]) dp[i] += dp[i - 2];
		dp[i] %= NUM97; // 1000000007 で割る
	}
	std::cout << dp[N] << std::endl;
	return 0;
}