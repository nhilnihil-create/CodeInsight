#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

int main() {
	long long N; std::cin >> N;
	std::vector<int> H(N);
	for (auto& r : H) std::cin >> r;
	for (int i = 1; i < N; ++i) {
		if(H[i-1] > H[i])
			if (H[i - 1] > H[i] + 1) {
				std::cout << "No" << std::endl;
				return 0;
			}
			else {
				++H[i];
			}
	}
	std::cout << "Yes" << std::endl;

	return 0;
}
