#include <stdio.h>


int main() {
	int H[50] = {};
	int W[50] = {};
	int n = 0;
	bool q=true;
	for (;;) {
		scanf("%d %d", &H[n], &W[n]);
		if (H[n] == 0)break;
		n++;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < H[k]; i++) {
			for (int j = 0; j < W[k]; j++) {
				if (q) {
					printf("#");
					q = false;
				}
				else {
					printf(".");
					q = true;
				}
			}
			printf("\n");
			if (i%2==0)q = false;
			else q = true;
		}
		printf("\n");
		q = true;
	}

	return 0;
}