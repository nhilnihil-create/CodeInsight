#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#define pi 3.14159265358979323846264338327950

int main() {
	int X; std::cin >> X;
	for (int i{ 1 }; i <= X; ++i) {
		if (i * 108 / 100 == X) {
			std::cout << i << std::endl;
			return 0;
		}
	}
	std::cout << ":(" << std::endl;
	return 0;
}