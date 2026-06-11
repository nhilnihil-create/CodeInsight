#include <stdio.h>

int main() {
	int A;
	int B = 2; 
	scanf("%d", &A);
	
	if(A % B == 0) {
	printf("%d\n", A/B);
	}
	
	else
	printf("%d\n", (A/B)+1);
	
	return 0;
}