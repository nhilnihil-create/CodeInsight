#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	int X;
	(void)scanf("%d", &X);
	int rank = 10 - (int)(X / 200);
	printf("%d", rank);
}