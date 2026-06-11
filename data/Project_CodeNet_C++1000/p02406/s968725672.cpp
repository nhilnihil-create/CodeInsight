#include <cstdio>

int main()
{
	int n; scanf("%d", &n);
	
	for (int i = 1; i <= n; ++i) {
		if (i % 3 == 0 || i % 10 == 3) printf(" %d", i);
		else {
			int x = i;
			while (x) {
				x /= 10;
				if (x % 10 == 3) {
					printf(" %d", i);
					break;
				}
			}
		}
	}

	printf("\n");
}