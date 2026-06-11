#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>

int main() {
	int N; std::cin >> N;
	std::vector<int> A(N);
	std::vector<int> B(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> A[i];
		B[i] = A[i];
	}
	std::sort(B.begin(), B.end());
	for (auto& r : A)
		if (r < B[N - 1]) std::cout << B[N - 1] << std::endl;
		else std::cout << B[N - 2] << std::endl;

	return 0;
}