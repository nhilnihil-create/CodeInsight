#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	long long A, B, C, K;
	(void)scanf("%lld%lld%lld%lld", &A, &B, &C, &K);
	if (A < K) {
		K -= A;
		if (B < K) {
			K -= B;
		}
		else {
			K = 0;
		}
	}
	else {
		A = K;
		K = 0;
	}
	printf("%lld", A - K);
}