#include <stdio.h>

int main() {
	int a = 500;
	int b, c, d;
	scanf("%d %d", &b, &c);
	
	d = a * b;
	
	if(d < c) {
		printf("No");
	} else {
		printf("Yes");
	}
	
	return 0;
}