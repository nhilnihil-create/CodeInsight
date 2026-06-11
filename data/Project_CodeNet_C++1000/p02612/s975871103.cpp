#include <iostream>

int main() {
	int N; std::cin >> N;
	if (N % 1000 != 0)
		std::cout << 1000 - (N % 1000) << std::endl;
	else
		std::cout << 0 << std::endl;

	return 0;
}
