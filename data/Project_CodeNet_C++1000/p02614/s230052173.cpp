#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	int H, W, K; std::cin >> H >> W >> K;
	std::vector<std::vector<char>> M(H, std::vector<char>(W));
	for (auto i{ 0 }; i < H; ++i)
		for (auto j{ 0 }; j < W; ++j)
			std::cin >> M[i][j];
	int ans = 0;
	for (int bit_h = 0; bit_h < (1 << H); ++bit_h)
		for (int bit_w = 0; bit_w < (1 << W); ++bit_w) {
			int count = 0;
			for (int h = 0; h < H; ++h)
				for (int w = 0; w < W; ++w) {
					if (bit_h & (1 << h) || bit_w & (1 << w)) continue;
					if (M[h][w] == '#') ++count;
				}
			if (count == K) ++ans;
		}
	std::cout << ans << std::endl;

	return 0;
}