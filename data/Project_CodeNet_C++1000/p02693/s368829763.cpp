#include <stdio.h>

int main() {

	int K, A, B;
	
	scanf("%d", &K);
	scanf("%d %d", &A, &B);
	
	int M = B%K;
	int N = B-M;
	
	if (N>=A) {
		printf("OK\n");
	}
	else {
		printf("NG\n");
	}

    return 0;
}
