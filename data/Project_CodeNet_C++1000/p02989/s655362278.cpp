#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int N; std::cin >> N;
	std::vector<int> D(N);
	for (auto& r : D) std::cin >> r;
	std::sort(D.begin(), D.end());
	std::cout << D[N / 2] - D[N / 2 - 1] << std::endl;

	return 0;
}