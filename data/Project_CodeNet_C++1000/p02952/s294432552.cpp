#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	int N; std::cin >> N;
	int count{ 0 };
	for (auto i{ 1 }; i <= N; ++i) {
		if (i < 10) ++count;
		if (1000 > i && 99 < i) ++count;
		if (100000 > i && 9999 < i) ++count;
		if (10000000 > i && 999999 < i) ++count;
	}
	std::cout << count << std::endl;

	return 0;
}
