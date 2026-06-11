#include <iostream>
#include <algorithm>
#include <cmath>

int main() {
	long long X, K, D; std::cin >> X >> K >> D;
	X = std::abs(X);

	long long div = std::min(K, X / D);
	K -= div;
	X -= div * D;
	if (K % 2 == 0) std::cout << X << std::endl;
	else std::cout << D - X << std::endl;
	

	return 0;
}