#include <stdio.h>

int main () {
	int H, A, times;
	scanf("%d%d", &H, &A);
	H % A <= 0 ? times = H / A : times = H / A + 1;
	printf("%d", times);
	return 0;
}