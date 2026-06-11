#include <stdio.h>

int main () {
	int l, r, d, tot = 0;
	scanf("%d %d %d", &l, &r, &d, &tot);
	while (l <= r ) {
		if (l % d == 0) {
			tot = tot + 1;
		}
		l++;
	}
	printf("%d\n", tot);
	return 0;	
}