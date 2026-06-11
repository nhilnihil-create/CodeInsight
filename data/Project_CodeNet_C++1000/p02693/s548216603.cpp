#include <stdio.h>

int main() {
	int K, A, B;
	scanf("%d", &K);
	scanf("%d %d", &A, &B);
	
	int ans = 0;
	for(int p = A; p <= B;  p++) {
		if(p % K == 0) {
			ans++;
		}
	} if(ans > 0) {
		printf("OK\n");
	} else {
		printf("NG\n");
	}

	
	return 0;
}