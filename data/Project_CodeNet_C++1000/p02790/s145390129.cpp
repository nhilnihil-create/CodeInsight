#include <iostream>

int main() {
	int a, b;
	std::cin >> a >> b;

	if (a < b) {
		std::cout << std::string(b, a + '0');
	}
	else
		std::cout << std::string(a, b + '0');
}