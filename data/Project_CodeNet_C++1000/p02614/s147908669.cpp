#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cmath>

std::vector<int> onesIndex(int n) {
	std::vector<int> ret;

	for (int k = 0; n != 0; ++k) {
		if (n % 2 == 1) {
			ret.push_back(k);
		}
		n = n / 2;
	}

	return ret;
}

int main() {
	int h, w, k;
	std::cin >> h >> w >> k;
	std::vector<std::vector<char>> grid;
	std::vector<int> rowSum(h);
	std::vector<int> heightSum(w);
	int t = 0;
	for (int i = 0; i < h; ++i) {
		std::string s;
		std::cin >> s;
		std::vector<char> v;
		for (int j = 0; j < w; ++j) {
			v.push_back(s[j]);
			if (s[j] == '#') {
				rowSum[i] += 1;
				heightSum[j] += 1;
				t += 1;
			}
		}
		grid.push_back(v);
	}

	int num = 0;
	for (int i = 0; i < std::pow(2,h); ++i) {
		for (int j = 0; j < std::pow(2,w); ++j) {
			int sum = 0;
			for (auto y : onesIndex(i)) {
				for (auto x : onesIndex(j)) {
					if (grid[y][x] == '#') {
						sum -= 1;
					}
				}
				sum += rowSum[y];
			}
			for (auto x : onesIndex(j)) {
				sum += heightSum[x];
			}

			if (t - sum == k) {
				num += 1;
			}
		}
	}

	std::cout << num;
}
