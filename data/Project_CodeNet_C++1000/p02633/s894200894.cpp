#include <stdio.h>
int main() {
	int x;
	scanf("%d", &x);
	long long ans = 360;
	while (ans % x != 0) {
		ans += 360;
	}
	printf("%d\n", ans / x);
}
