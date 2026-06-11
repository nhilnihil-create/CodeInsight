#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	long long N, K; std::cin >> N >> K;
	std::cout << std::min(N % K, K - N % K) << std::endl;

	return 0;
}