#include <stdio.h>

int main() {
	long long Zx, count = 0;
	scanf("%lld", &Zx);
	for (int u = 1; u <= Zx; u++) {
		if (u % 3 != 0 && u % 5 != 0) {
			count += u;
		}
	}
	printf("%lld", count);
	return 0;
}