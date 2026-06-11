#include <stdio.h>
#pragma warning (disable:4996)

//prototype
int sum(int);

int main() {
	//input
	int N, M;
	(void)scanf("%d %d", &N, &M);

	//output
	int A, s = 0;
	for (int i = 0; i < M; i++) {
		(void)scanf("%d", &A);
		s += A;
	}
	if ((N - s) >= 0)printf("%d", N - s); else printf("-1");
}