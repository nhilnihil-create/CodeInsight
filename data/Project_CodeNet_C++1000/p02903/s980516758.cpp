#include <cstdio>

int N, M, A, B;

int main() {
	scanf("%d%d%d%d", &N, &M, &A, &B);
	for (int i = 1; i <= N; ++i, puts(""))
		for (int j = 1; j <= M; ++j)
			printf("%d", (i <= B) ^ (j <= A));
	return 0;
}