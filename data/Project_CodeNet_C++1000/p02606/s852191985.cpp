#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	int L, R, d;
	(void)scanf("%d%d%d", &L, &R, &d);
	int count = 0;
	int i = 1;
	while (R >= d * i) {
		if (L > d * i) {
			i++;
			continue;
		}
		i++;
		count++;
	}
	printf("%d", count);
}