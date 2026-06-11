#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	long long H, W; std::cin >> H >> W;
	long long m = W * H;
	if (H == 1 || W == 1) {
		std::cout << 1 << std::endl;
		return 0;
	}
	if (H % 2 == 1 && W % 2 == 1)
		std::cout << m / 2 + 1 << std::endl;
	else
		std::cout << m / 2 << std::endl;

	return 0;
}