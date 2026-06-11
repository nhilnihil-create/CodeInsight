#include <cstdio>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);

	if (a >= b) {
		int i;
		for (i = 0; i < a; i++)
			printf("%d", b);
	} else {
		int i;
		for (i = 0; i < b; i++)
			printf("%d", a);
	}
			printf("\n");
	return 0;
}
