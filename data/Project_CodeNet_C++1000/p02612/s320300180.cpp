#include <stdio.h>

#pragma warning (disable:4996)


int main() {
	int N;
	(void)scanf("%d", &N);
	while (N > 0) {
		N -= 1000;
	}
	N = -N;
	printf("%d", N);
}