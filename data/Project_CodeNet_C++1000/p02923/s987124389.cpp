#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main() {
	int N; std::cin >> N;
	std::vector<int> H(N); for (auto& r : H) std::cin >> r;
	int ans = 0; int count = 0;
	for (int i = 0; i < N - 1; ++i)
		if (H[i] >= H[i + 1]) ++count;
		else {
			ans = std::max(ans, count);
			count = 0;
		}
	std::cout << std::max(ans, count) << std::endl;

	return 0;
}