#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	long long A, B, C, K; std::cin >> A >> B >> C >> K;
	if (K <= A)
		std::cout << K << std::endl;
	else if (A < K && K <= A + B)
		std::cout << A << std::endl;
	else
		std::cout << A - (K - A - B) << std::endl;

	return 0;
}