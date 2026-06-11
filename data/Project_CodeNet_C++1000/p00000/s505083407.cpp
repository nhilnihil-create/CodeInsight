#include<stdio.h>

int main() {
	int i = 8;
	while (i++ < 89) {
		printf("%dx%d=%d\n", i / 9, i % 9 + 1, i / 9 * (i % 9 + 1));
	}
	return 0;
}
