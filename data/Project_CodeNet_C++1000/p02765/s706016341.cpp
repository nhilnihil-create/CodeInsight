#include <stdio.h>

int main() {
	int a, b, c, d;
	scanf("%d %d", &a, &b);
	
	if(a < 10) {
		c = 100 * (10 - a);
		d = b + c;
		printf("%d", d);
	} else {
		printf("%d", b);
	}
	
	return 0;
}