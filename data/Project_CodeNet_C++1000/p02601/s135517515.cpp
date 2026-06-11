#include <stdio.h>

int main() {
	int a, b, c, k;
	scanf("%d%d%d%d", &a, &b, &c, &k);
	k += 1;
	while (k--) {
		if (b <= a) b <<= 1;
		else if (c <= b) c <<= 1;
		else {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
}
