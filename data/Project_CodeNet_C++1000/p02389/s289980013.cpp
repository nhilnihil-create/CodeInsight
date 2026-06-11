#include <stdio.h>

int
main(void)
{
	char line[80];
	int a;
	int b;

	if (gets(line)) {
		if (sscanf(line, "%d %d", &a, &b) == 2) {
			printf("%d %d\n", a*b, 2*(a+b));
		}
	}

	return 0;
}