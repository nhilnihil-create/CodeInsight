#include <iostream>
#include<string>

int main() {
	int x, y;
	while (std::cin >> x >> y, x || y) {
		if (x > y) {
			std::cout << y << " " << x << std::endl;
		}
		else {
			std::cout << x << " " << y << std::endl;
		}
	}
	return 0;
}
