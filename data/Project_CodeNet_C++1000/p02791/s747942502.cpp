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
	int min = N + 1;
	int count = 0;
	for (int i = 0; i < N; ++i) {
		int p;  std::cin >> p;
		min = std::min(p, min);
		if (min == p)++count;
	}
	std::cout << count << std::endl;

	return 0;
}
