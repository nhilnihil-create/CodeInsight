#include <stdio.h>

int main() 
{
	int x, y;
		scanf("%d %d", &x, &y);
	int z = x / y;
	
	if (x % y != 0) {
			z ++;
	}
		printf("%d", z);
	return 0;
}