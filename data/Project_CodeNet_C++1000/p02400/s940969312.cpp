#include <iostream>
#include <cstdio>

int main() {
	double r;
	const double pi = 3.1415926535897932384;
	std::cin >> r;

	printf("%.15f %.15f\n", r * r * pi, 2 * r * pi);

	return 0;
}