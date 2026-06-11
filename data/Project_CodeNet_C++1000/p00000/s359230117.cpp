#include <stdio.h>

int main(void)
{
	int a, b;
	a = 1;
	b = 1;
	
	while (a < 10) {
		while (b < 10) {
			printf("%dx%d=%d\n", a, b, a * b);
			++b;
		}
		++a;
		b = 1;
	}

	return 0;
}

