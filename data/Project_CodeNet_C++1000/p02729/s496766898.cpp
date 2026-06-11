#include <stdio.h>

int main () {
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d\n", x*(x-1)/2 + y*(y-1)/2);
	
	return 0;
}