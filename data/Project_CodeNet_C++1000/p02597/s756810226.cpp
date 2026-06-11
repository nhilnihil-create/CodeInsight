#include <iostream>
#include <vector>

int main() {
	long long N; std::cin >> N;
	std::vector<char> C(N);
	for (auto& r : C)
		std::cin >> r;
	long long count_r{ 0 };
	for (auto i{ 0 }; i < N; ++i) {
		if (C.at(i) == 'R')
			++count_r;
	}
	long long count_right_r{ 0 };
	for (auto i{ 0 }; i < count_r; ++i) {
		if (C.at(i) == 'R')
			++count_right_r;
	}
	std::cout << count_r - count_right_r << std::endl;

	return 0;
}
