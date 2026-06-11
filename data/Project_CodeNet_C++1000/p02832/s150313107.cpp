#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

int main(){
	int N; std::cin >> N;
	std::vector<int> H(N);
	for (auto& r : H) std::cin >> r;
	int count = 0;
	int i = 1;
	for (auto& r : H) {
		if (i == r) {
			++count;
			++i;
		}
	}

	std::sort(H.begin(), H.end());
	if (H[0] != 1) {
		std::cout << -1 << std::endl;
		return 0;
	}
	std::cout << N - count << std::endl;

	return 0;
}