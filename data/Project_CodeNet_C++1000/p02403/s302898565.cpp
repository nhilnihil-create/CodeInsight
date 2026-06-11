#include <stdio.h>


int main() {
	int H[50] = {};
	int W[50] = {};
	int n = 0;
	for (;;) {
		scanf("%d %d", &H[n], &W[n]);
		if (H[n] == 0)break;
		n++;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < H[k]; i++) {
			for (int j = 1; j < W[k]; j++) {
				printf("#");
			}
			printf("#\n");
		}
		printf("\n");
	}

	return 0;
}