#include<iostream>
#include<vector>

const long long MAX = 1e18;

int main() {

	int N;
	std::cin >> N;
	std::vector<long long> A(N);
	for (int i = 0; i < N; i++) {
		std::cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		if (A[i] == 0) {
			std::cout << 0 << std::endl;
			return 0;
		}
	}
	
	long long answer = 1;
	for (int i = 0; i < N; i++) {
		if (answer > MAX / A[i]) {
			std::cout << -1 << std::endl;
			return 0;
		}
		else answer *= A[i];
	}
	
	std::cout << answer << std::endl;
	return 0;
}