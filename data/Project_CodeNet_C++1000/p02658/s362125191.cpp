#include <stdio.h>
#pragma warning (disable:4996)

#define ORDER 1000000000000000000

int main() {
	//input
	int N;
	(void)scanf("%d", &N);
	
	//output
	long long A, pi = 1;
	for (int i = 0; i < N; i++) {
		(void)scanf("%lld", &A);
		if (A == 0) {
			pi = 0;
			break;
		}
		if (pi > (ORDER / A)) {
			pi = -1;
			continue;
		}
		if (pi != -1)pi *= A;
	}
	printf("%lld", pi);
}