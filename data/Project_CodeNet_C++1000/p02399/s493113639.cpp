#include <cstdio>

int main(void) {
	int a, b;
	std::scanf("%d %d", &a, &b);
	const int d = a / b, r = a % b;
	const double f = static_cast<double>(a) / static_cast<double>(b);
	std::printf("%d %d %.5f\n", d, r, f);
	return 0;
}