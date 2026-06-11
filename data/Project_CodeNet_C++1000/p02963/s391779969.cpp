#include <bits/stdc++.h>

const int SQRT = int(1e9);

int main() {
	long long s;
	scanf("%lld", &s);
	int x = s / SQRT + (s % SQRT != 0);
	int b = s / x + (s % x != 0);
	int y = 1LL * x * b - s;
	printf("0 0 %d %d 1 %d\n", x, y, b);
}