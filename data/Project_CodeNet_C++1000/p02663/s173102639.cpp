#include <stdio.h>

int main() {
	int h1, m1, h2 ,m2 ,k;
	int h = 0, m = 0;
	scanf ("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
	
	h = h2 - h1;
	m = m2 - m1;
	
	printf ("%d", 60 * h + m - k);
	
//	if (m < 0) {
	//	m *= -1;
	//}
	
	//if (h + m == k) {
	//	printf ("%d", k);
//	}
//	else {
//	printf ("%d\n", h + m - k);
//	}
	
	return 0;
}