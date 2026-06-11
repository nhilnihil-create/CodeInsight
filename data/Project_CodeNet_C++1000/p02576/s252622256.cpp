#include <cstdio>

int main() {
	int n, x, t;
	std::scanf("%d%d%d", &n, &x, &t);
	std::printf("%d\n", ((n / x) + (bool)(n % x)) * t);
	return 0;
}