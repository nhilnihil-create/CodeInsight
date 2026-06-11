#include<stdio.h>

int main() {
	
	// print a + a^2 + a^3
	
	int A;
	int sum = 0;	
	scanf("%d", &A);
	int B = A*A;
	int C = A*A*A;
	sum = A + B + C;
	
	printf("%d", sum);
	
	return 0;
}