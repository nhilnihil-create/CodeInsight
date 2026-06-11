#include <iostream>
#include <vector>
#include<algorithm>
#include <string>
#define lint long long
const long long INF = (1LL << 60);
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

lint N, H, W;
std::vector<std::string> S;
std::vector<std::vector<bool>> seen(H, std::vector<bool>(W));
const std::vector<int> dx { 1, 0 };
const std::vector<int> dy { 0, 1 };

lint DP() {
	std::vector<std::vector<lint>> dp(H, std::vector<lint>(W, INF));
	if (S[0][0] == '#') dp[0][0] = 1;
	else dp[0][0] = 0;
	for (lint i = 0; i < H; ++i) {
		for (lint j = 0; j < W; ++j) {
			for (lint d = 0; d < 2; ++d) {
				lint h = i + dx[d];
				lint w = j + dy[d];
				if (h >= H || w >= W) continue;
				lint flag = 0;
				if (S[h][w] == '#' && S[i][j] == '.') flag = 1;
				chmin(dp[h][w], dp[i][j] + flag);
			}
		}
	}
	return dp[H - 1][W - 1];
}

int main(){
	std::cin >> H >> W;
	S.resize(H);
	for (int i{ 0 }; i < H; ++i)
			std::cin >> S[i];
	std::cout << DP() << std::endl;
}