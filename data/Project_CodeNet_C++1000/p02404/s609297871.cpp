#include <stdio.h>

int main(void){
	int H;
	int W = 301;
	do {
		if (W <= 300) {
			for (int h = 1; h <= H; h++) {
				for (int w = 1; w <= W; w++) {
					if (h == 1 || h == H || w == 1 || w == W) {
						printf("#");
					} else {
						printf(".");
					}
					
				}
				printf("\n");
			}
			printf("\n");
		}
		scanf("%d %d", &H, &W);
	} while (H > 0 && W > 0);
	
	return 0;
}