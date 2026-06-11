#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	int N, A;
	(void)scanf("%d%d", &N, &A);

	int count, n;
	if (A % 2 == 0)count = 0;
	else count = 1;
	if (N % 2 == 0)n = N / 2 - 1;
	else n = (N - 1) / 2;

	for (int i = 0; i < n; i++) {
		(void)scanf("%*d%d", &A);
		if (A % 2 == 1)count++;
	}

	printf("%d", count);
}