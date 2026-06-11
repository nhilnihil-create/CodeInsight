#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
	int N, K; std::cin >> N >> K;
	std::vector<int> P(N);
	for (auto& r : P) std::cin >> r;
	std::sort(P.begin(), P.end());
	int ans{ 0 };
	for (auto i{ 0 }; i < K; ++i)
		ans += P[i];
	std::cout << ans << std::endl;

	return 0;
}