#include<stdio.h>

int main() {
	int i, j;
	int h, w;

	while (1) {
		scanf("%d %d", &h, &w);
		if (!(h||w))break;
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++)printf("#");
			printf("\n");
		}
		printf("\n");
	}
	return 0;

}