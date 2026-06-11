#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> x(n);
	for (auto &e : x) {
		std::cin >> e;
	}
	
	int sum;
	int min = 1145141919;
	auto sq = [](int x) { return x * x; };
	for (int i = 1; i <= 100; i++) {
		sum = 0;
		for (auto e : x) {
			sum += sq(e - i);
		}
		if (sum < min) min = sum;
		else break;
	}
	
	std::cout << min << std::endl;
	
	return 0;
}
