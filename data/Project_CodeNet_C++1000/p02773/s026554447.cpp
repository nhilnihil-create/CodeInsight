#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

int main() {
	int N; std::cin >> N;
	std::map<std::string, int> MAP ;
	int max = 0;
	for (int i = 0; i < N; ++i) {
		std::string s; std::cin >> s;
		MAP[s]++;
	}
	for (auto& r : MAP)
		max = std::max(r.second, max);
	for (auto& r : MAP)
		if (r.second == max)
			std::cout << r.first << std::endl;

	return 0;
}
