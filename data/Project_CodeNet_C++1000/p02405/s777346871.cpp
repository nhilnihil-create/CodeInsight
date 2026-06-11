
#include <stdio.h>

int main() {
	int H, W;
	while (1) {
		scanf("%d %d", &H, &W);
		if (H == 0 && W == 0) {
			break;
		}
		for (int i = 0; i < H; i++) {
			for (int k = 0; k < W; k++) {
				if (i % 2 == 0) {
					if (k % 2 == 0) {
						printf("#");
					}
					else {
						printf(".");
					}
				}
				else {
					if (k % 2 == 0) {
						printf(".");
					}
					else {
						printf("#");
					}
				}
				
					
			}
			printf("\n");
		}
		printf("\n");
	}
}
