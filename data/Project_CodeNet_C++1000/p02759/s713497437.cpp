#include <stdio.h>

int main() {
    int N, M, C, D, total;
    
	scanf("%d", &N);
	C = N / 2;
	D = N % 2;
    total = C + D;

    printf("%d\n", total);
    
return 0;
}