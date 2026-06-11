#include <stdio.h>

int main() {
	int H1, M1, H2, M2, K;
	scanf("%d %d %d %d %d", &H1, &M1, &H2, &M2, &K);
	
	int H = H2 - H1;
	int M = M2 - M1;
	M += H * 60;
	printf("%d\n", M - K);
	
	return 0;
}