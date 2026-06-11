#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>
#define intt long long

int main() {
	std::vector<int> x(5);
	for (auto& r : x)
		std::cin >> r;
	for (int i = 0; i < 5; ++i) {
		if (x[i] == 0) {
			std::cout << i + 1 << std::endl;
			return 0;
		}
	}

}
