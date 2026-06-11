#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#define MAX 1000000000000000000

int main() {
	long long N; std::cin >> N;
	std::vector<long long> P(N);
	for (auto& r : P) {
		std::cin >> r;
		if (r == 0) {
			std::cout << 0 << std::endl;
			return 0;
		}
		if (r > MAX) {
			std::cout << -1 << std::endl;
			return 0;
		}
	}
	long long ans{ 1 };
	for (int i{ 0 }; i < N; ++i) {
		if (MAX / ans < P[i]) {
			std::cout << -1 << std::endl;
			return 0;
		}
		ans *= P[i];
	}
	std::cout << ans << std::endl;

	return 0;
}