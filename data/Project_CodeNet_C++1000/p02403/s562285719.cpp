#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int H, W,i,j;

	while (1){
		scanf("%d %d", &H, &W);
		if (H == 0 && W == 0){
			break;
		}
			for (i = 0; i < H; i++){
				for (j = 0; j < W; j++){
					putchar('#');
				}
				putchar('\n');
			}
			putchar('\n');
	}

	return 0;
}