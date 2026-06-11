#include <stdio.h>

int main (){

int L, R, d, ctr = 0;

scanf ("%d %d %d", &L, &R, &d);

while (L <= R) {
	
	if ( L % d == 0) {
		ctr = ctr + 1;
	}
	L++;
}

	printf("%d", ctr);
}