#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

long long count(long long N) {
	if (N == 1) return 1;
	return count(N / 2) * 2 + 1;
}

int main() {
	long long H; std::cin >> H;
	std::cout << count(H) << std::endl;

	return 0;
}