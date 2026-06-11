#include <stdio.h>
#pragma warning (disable:4996)

int main() {
	char S[21] = {};
	(void)scanf("%s", S);
	printf("%c%c%c", S[0], S[1], S[2]);
}