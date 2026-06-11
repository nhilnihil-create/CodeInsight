#include <iostream>
#include <cstdio>

auto area(int a, int b) -> int {
	return a * b;
}

auto perimeter(int a, int b) -> int {
	return (a * 2) + (b * 2);
}

auto main() -> int {
	int a, b;
	std::cin >> a;
	std::cin >> b;

	printf("%d %d\n",
		area(a, b),
		perimeter(a, b));
}