#include <stdio.h>
#include <math.h>

#define M_PI 3.141592653589793

int main(void) {

	int i = 0, j, k, l;
	int H[10000], W[10000];

	while (1) {
		scanf("%d %d", &H[i], &W[i]);
		if (H[i] == 0 && W[i] == 0) {
			break;
		}
		else {
			i++;
		}
	}

	for (l = 0; l < i; l++) {
		for (j = 0; j < H[l]; j++) {
			for (k = 0; k < W[l]; k++) {
				if (k == 0 || k == W[l] - 1 || j == 0 || j == H[l] - 1) {
					printf("#");
				}
				else {
					printf(".");
				}
			}printf("\n");
		}printf("\n");
	}

	return 0;
}