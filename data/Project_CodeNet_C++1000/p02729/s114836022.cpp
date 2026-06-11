#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	
	a = ((a * a) / 2) - (a / 2);
	b = ((b * b) / 2) - (b / 2);
	
	printf("%d", a + b);
	
	return 0;
}