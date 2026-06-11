#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int N; std::cin >> N;
	std::vector<long long> X(N);
	long long sum{ 0 };
	long long ans{ 1000000000000000000 };
	for (auto& r : X) std::cin >> r;
	for (long long i{ 1 }; i <= 200; ++i) {
		sum = 0;
		for (auto r : X) {
			sum += (r - i) * (r - i);
		}
		if (sum < ans) ans = sum;
	}
	std::cout << ans << std::endl;
	return 0;
}