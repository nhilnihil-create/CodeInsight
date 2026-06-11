#include <stdio.h>

#pragma warning(disable : 4996)

int main(void) {
	int x;
	(void)scanf("%d", &x);

	if (x == 0)
		printf("%d", 1);
	else
		printf("%d", 0);

	return 0;
}