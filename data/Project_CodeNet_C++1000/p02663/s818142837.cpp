#include <stdio.h>

int main() {
	int h1, m1, h2, m2, k;
	
	scanf("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
	
	int d;
	d = (h2  - h1) * 60;
	
	int e;
	e = m2 - m1;
	
	printf("%d", (d + e) - k);

	return 0;
	
	}
