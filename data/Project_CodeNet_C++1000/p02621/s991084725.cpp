#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int total = n + (n * n) + (n * n * n);
	printf("%d\n", total);
	
	return 0;
}