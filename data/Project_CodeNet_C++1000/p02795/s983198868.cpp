#include <stdio.h>

int main() {
	int r, c, n, count = 0, calc = 0;;
	scanf("%d", &r);
	scanf("%d", &c);
	scanf("%d", &n);
	
	while(calc < n) {
		if(r < c) {
			calc += c;
		} else {
			calc += r;
		}
		count++;
	}
	printf("%d", count);
	
	return 0;
}