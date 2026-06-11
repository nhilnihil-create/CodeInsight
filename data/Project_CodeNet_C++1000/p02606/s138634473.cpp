#include <stdio.h>

int main() {
	int L, R, o, ctr = 0;
	scanf("%d %d %d", &L, &R, &o);
	while(L <= R){
		if (L % o == 0){
		ctr = ctr + 1;
		}
		L++;
	}
	printf("%d", ctr);
	return 0;
}
