#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int K, N; std::cin >> K >> N;
	std::vector<int> A(N);
	for (auto& r : A) std::cin >> r;
	std::vector<int> Dis(N);
	Dis[0] = A[0] + K - A[N - 1];
	for (auto i = 1; i < N; ++i) {
		Dis[i] = A[i] - A[i - 1];
	}
	std::sort(Dis.begin(), Dis.end());
	int sum = 0;
	for (auto& r : Dis)
		sum += r;
	std::cout << sum - Dis[N - 1] << std::endl;
	return 0;
}