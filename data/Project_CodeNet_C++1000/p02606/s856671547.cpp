#include <stdio.h>

int main() {
	int L, R, d, ctr = 0;
	scanf ("%d %d %d", &L, &R, &d);
	
	for (int i = L; i <= R; i++){
		if (i % d == 0){
			ctr += 1;
		}
	}
	printf ("%d", ctr);
	return 0;
}