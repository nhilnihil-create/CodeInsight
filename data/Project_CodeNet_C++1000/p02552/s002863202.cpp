#include <iostream>

int main()

{
	int x;
	std::cin >> x;
	if (x == 0) {
		std::cout << ++x;
	}
	else if (x == 1) {
		std::cout << --x;
	}
}