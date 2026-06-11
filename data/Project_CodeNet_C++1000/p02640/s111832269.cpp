#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
	int X, Y; std::cin >> X >> Y;
	for (auto i{ 0 }; i <= X; ++i) {
		int ans = ((X - i) * 2) + (4 * i);
		if (ans == Y) {
			std::cout << "Yes" << std::endl;
			return 0;
		}
	}
	std::cout << "No" << std::endl;
	return 0;
}