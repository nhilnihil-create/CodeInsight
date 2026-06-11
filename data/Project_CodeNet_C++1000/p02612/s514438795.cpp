#include <iostream>
#include <string>

int main() {

	int N;
	std::cin >> N;
	int change;

	change = N % 1000;

	if (0 == change) {
		std::cout << "0" << std::endl;
	}else {
		change = 1000 - change;
		std::cout << change << std::endl;
	}

	return 0;
}