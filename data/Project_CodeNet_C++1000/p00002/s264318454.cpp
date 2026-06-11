#include <stdio.h>

int
main(void)
{
	char line[80];
	long a;
	long b;
	long c;
	int k = 1;

	while (gets(line)) {
		if (sscanf(line, "%ld %ld", &a, &b) == 2) {
			c = a + b;
			k = 1;
			while (c / 10 > 0) {
				k ++;
				c /= 10;
			}
			printf("%d\n", k);
		}
	}

	return 0;
}