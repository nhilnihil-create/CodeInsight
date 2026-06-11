#include <stdio.h>

int main(void){
	int n, x;
	scanf("%d", &n);
	
	for (int i = 1; i <= n; i++) {
		x = i;
		if (x % 3 == 0) {
			printf(" %d", i);
		} else {
			do {
				if (x % 10 == 3) {
					printf(" %d", i);
					x = 0;
				} else {
					x /= 10;
				}
			} while (x);
		}
	}

	printf("\n");
	return 0;
}