#include<cstdio>
int lowbit(int x) {
	return x & -x;
}
int main() {
	int N; scanf("%d", &N);
	if( lowbit(N) == N ) {
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=2;i<N;i+=2) {
		printf("1 %d\n1 %d\n", i, i+1);
		printf("%d %d\n%d %d\n", i, i+1+N, i+N, i+1);
	}
	if( N % 2 == 0 ) {
		int p = lowbit(N);
		printf("%d %d\n", p+1, N);
		printf("%d %d\n", N-p, 2*N);
	}
	printf("%d %d\n", 1 + N, 2 + N);
}