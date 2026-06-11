#include <stdio.h>

int main () {
	int l, r, d;
	int ctr = 0;
	scanf("%d", &l);
	scanf("%d", &r);
	scanf("%d", &d);
	
	for (int i = l; i <= r; i++) {
		if (i % d == 0) {
			ctr++;
		}
	}
	printf("%d", ctr);
	
	
	return 0;
}