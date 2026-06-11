#include <iostream>

int main() {
	long long K; std::cin >> K;
	if (K % 2 == 0 || K % 5 == 0) {
		std::cout << -1 << std::endl;
		return 0;
	}
	long long digit = 1;
	long long N = 7 % K;
	while (N != 0) {
		N = (N * 10 + 7) % K;
		++digit;
	}
	std::cout << digit << std::endl;
}
