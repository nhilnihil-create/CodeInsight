#include <stdio.h>

int main () {
	int h, w, n;
	int p = 0;
	scanf("%d %d %d", &h, &w, &n); 
	
	if ((n / w) < (n / h)) {
		if (n % w == 0) {
			p = n / w;
		} else {
			p = n / w + 1;
		}
	} else {
		if (n % h == 0) {
			p = n / h;
		} else {
			p = n / h + 1;
		}
	}
	printf("%d", p); 
	return 0;
}