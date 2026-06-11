#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
	int X, N; std::cin >> X >> N;
	std::vector<int> P(N);
	int ans = 0;
	for (auto& r : P) std::cin >> r;
	for (auto i{ 0 }; i < 101; ++i) {
		bool flag_m = false;
		bool flag_l = false;
		int less = X - i;
		int more = X + i;
		for (auto j{ 0 }; j < N; ++j) {
			if (less == P[j]) {
				flag_l = true;
			}
			if (more == P[j]) {
				flag_m = true;
			}
		}
		if (flag_l == false) {
			ans = less;
			break;
		}
		if (flag_m == false) {
			ans = more;
			break;
		}
	}
	std::cout << ans << std::endl;
	
	return 0;
}