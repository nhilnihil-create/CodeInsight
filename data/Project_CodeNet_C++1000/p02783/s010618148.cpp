#include <stdio.h>

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	
	int c = a / b;
	
	if(a % b == 0) {
		printf("%d", c);
	} else {
		printf("%d", c + 1);
	}
	
	return 0;
}