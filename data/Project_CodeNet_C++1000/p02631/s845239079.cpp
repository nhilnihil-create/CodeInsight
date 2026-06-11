#include <stdio.h>

#define LL long long
#define ULL unsigned long long
#define UI unsigned int
#define UC unsigned char
#define UL unsigned long

int main() {
	int N;
	scanf("%d", &N);
	int a[N], iSigma = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		iSigma ^= a[i];
	}

	for (int i = 0; i < N; i++)
		printf("%d ", iSigma ^ a[i]);
	printf("\n");
	
	return 0;
}
