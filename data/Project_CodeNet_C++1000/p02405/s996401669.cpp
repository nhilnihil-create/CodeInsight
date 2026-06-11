#include<stdio.h>
int main() {
	int a, b,i,j;
	while (scanf("%d %d", &a, &b) && a&&b) {
		for (i = 1; i <= a; ++i) {
			for (j = 1; j <= b; ++j) {
				if ((i+j) % 2==0) printf("#");
				else printf(".");
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
