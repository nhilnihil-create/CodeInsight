#include <stdio.h>
long long n, ans;
int main() {
	scanf("%lld", &n);
	if (n % 2) {
		printf("0\n");
		return 0;
	}
	n /= 2;
	while (n) {
		ans += n / 5;
		n /= 5;
	}
	printf("%lld\n", ans);
}
