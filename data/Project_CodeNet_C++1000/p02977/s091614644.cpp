#include <cstdio>

int N;

int main() {
	scanf("%d", &N);
	if (N == (N & -N)) return puts("No"), 0;
	puts("Yes");
	int M = 1 << (31 - __builtin_clz(N));
	printf("%d 1\n", M);
	printf("1 %d\n", M + 1);
	printf("%d %d\n", M + 1, M + N);
	printf("%d %d\n", M + N, 1 + N);
	printf("%d %d\n", 1 + N, M + 1 + N);
	for (int i = 2; i < N; i += 2) if (i != M)
		printf("%d %d\n", i + 1 + N, i),
		printf("%d 1\n", i),
		printf("1 %d\n", i + 1),
		printf("%d %d\n", i + 1, i + N);
	if (~N & 1)
		printf("%d %d\n", N, M + 1),
		printf("%d %d\n", N - M, N + N);
	return 0;
}