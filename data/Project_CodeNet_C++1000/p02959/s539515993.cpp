#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <iomanip>

int main() {
	long long N; std::cin >> N;
	std::vector<long long>A(N + 1);
	std::vector<long long>B(N);
	for (auto& r : A)
		std::cin >> r;
	for (auto& r : B)
		std::cin >> r;
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		if (A[i] + A[i + 1] <= B[i]) {
			ans += A[i] + A[i + 1];
			A[i + 1] = 0;
		}
		else if (A[i] <= B[i] && A[i] + A[i + 1] > B[i]) {
			ans += B[i];
			A[i + 1] -= B[i] - A[i];
		}
		else {
			ans += B[i];
		}

	}
	std::cout << ans << std::endl;
	
}
