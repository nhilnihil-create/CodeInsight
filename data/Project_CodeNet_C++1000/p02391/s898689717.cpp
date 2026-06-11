#include <iostream>

int main() {
	int a, b;

	std::cin >> a >> b;

	if (a >= -1000 && b <= 1000) {
		if (a > b)
			std::cout << "a > b" << std::endl;
		else if (a < b)
			std::cout << "a < b" << std::endl;
		else if (a == b)
			std::cout << "a == b" << std::endl;
	}

	return 0;
}