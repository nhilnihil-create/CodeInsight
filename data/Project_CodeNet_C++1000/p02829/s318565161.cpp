#include <stdio.h>

int main() {
	int a, b;
	scanf("%d\n %d", &a, &b);
	
	if (a == 1 && b == 2 || a == 2 && b == 1) {
		printf ("3");
	} else if (a == 1 && b == 3 || a == 3 && b == 1) {
		printf ("2");
	} else {
		printf ("1");
	}
	
	return 0;
}