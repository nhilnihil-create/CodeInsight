#include <cstdio>
int main() {
	int N, M; scanf("%d", &N);
	for(M = 0; (M << 1 | 1) <= N; M = (M << 1 | 1));
	if( N == 1 || M + 1 == N )
		puts("No");
	else {
		puts("Yes");
		int P = (M + 1) >> 1;
		for(int i=1;i<P;i++) {
			printf("%d %d\n", i + N + P, i);
			printf("%d %d\n", i, P);
			printf("%d %d\n", P, i + P);
			printf("%d %d\n", i + P, i + N);
		}
		printf("%d %d\n", P + N, N + 1);
		if( M != N ) {
			printf("%d %d\n", P, M + 1);
			printf("%d %d\n", M + 1 + N, M + 2 + N);
			for(int i=M+2;i<=N;i++) {
				int x = i - (M + 1);
				if( x < P ) printf("%d %d\n", i + N, x + P);
				else if( x == P ) printf("%d %d\n", i + N, x);
				else printf("%d %d\n", i + N, x - P);
				printf("%d %d\n", M + 1, i);
			}
		}
	}
}