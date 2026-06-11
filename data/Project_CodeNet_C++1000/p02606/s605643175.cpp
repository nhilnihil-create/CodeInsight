#include <stdio.h>

int main() {
	int l, r, d, i = 0;
	
	scanf("%d %d %d", &l, &r, &d);
	while (l<=r){
		if(l%d == 0) {
			i++;
		}
		l++;
	}
	printf ("%d", i);
	return 0;
}