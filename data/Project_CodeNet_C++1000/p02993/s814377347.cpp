#include <iostream>

int main() {
	char a, b, c, d;
	std::cin >> a >> b >> c >> d;
	if (a != b && b != c && c != d)
		std::cout << "Good\n";
	else std::cout << "Bad\n";
}
