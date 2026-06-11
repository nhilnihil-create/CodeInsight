#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

int main() {
	int N, K, Q; std::cin >> N >> K >> Q;
	std::vector<int> POINT(N);
	for(auto& r : POINT) r = -Q;
	std::vector<int> A(Q);
	for (auto& r : A) {
		std::cin >> r;
		POINT[r - 1] += 1;
	}
	for (auto& r : POINT) {
		if (r + K > 0)
			std::cout << "Yes" << std::endl;
		else
			std::cout << "No" << std::endl;
	}


}