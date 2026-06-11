#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);
	if (!(N & (N - 1)))
		return puts("No"), 0;
	puts("Yes");
	printf("%d %d\n", N + 1, 3);
	for (int i = 2; i < N; i += 2)
		printf("%d %d\n%d %d\n%d %d\n%d %d\n", i + 1, i, i, 1, 1, N + i + 1, N + i + 1, N + i);
	if (N % 2 == 0)
		for (int i = 2; i < N; ++i)
			if ((i ^ N ^ 1) >= 2 && (i ^ N ^ 1) < N) {
				printf("%d %d\n%d %d\n", i % 2 == 0 ? i : N + i, N, (i ^ N ^ 1) % 2 == 0 ? i ^ N ^ 1 : N + (i ^ N ^ 1), 2 * N);
				break;
			}
	return 0;
}
