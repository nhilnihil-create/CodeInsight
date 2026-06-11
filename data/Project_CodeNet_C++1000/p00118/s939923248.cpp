#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<char>> &vector, const int &x, const int &y, const char type) {
	if (0 <= y && vector.size() > y && vector.at(y).at(x) == type) {
		vector.at(y).at(x) = '\0';
		for (const auto &p : { std::make_pair(x + 1, y), std::make_pair(x - 1, y), std::make_pair(x, y + 1), std::make_pair(x, y - 1) }) {
			dfs(vector, p.first, p.second, type);
		}
	}
}
int main() {
	int h, w;
	while (std::cin >> h >> w && h != 0 && w != 0) {
		std::vector<std::vector<char>> vector(h, std::vector<char>(w + 2, '\0'));
		char *arg = new char[w + 2];
		for (auto i = 0; i < h; ++i) {
			std::cin >> arg;
			for (auto j = 0; j < w; ++j) {
				vector.at(i).at(j + 1) = arg[j];
			}
		}
		delete[] arg;
		int count = 0;
		for (auto y = 0; y < h; ++y) {
			for (auto x = 1; x <= w; ++x) {
				if (vector.at(y).at(x) != '\0') {
					++count;
					dfs(vector, x, y, vector.at(y).at(x));
				}
			}
		}
		std::cout << count << std::endl;
	}
	return 0;
}