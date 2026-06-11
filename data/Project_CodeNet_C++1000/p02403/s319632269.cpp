#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int i,j,k,c,H[100], W[100];
	i = 0;
	while (1){
		scanf("%d %d", &H[i], &W[i]);
		if (0 == H[i] && 0 == W[i]) {
			break;
		}
		i++;
	}
	c = i;
	for (k = 0; k < c; k++) {
		for (j = 0; j < H[k]; j++) {
			for ( i = 0; i <W[k] ; i++){
				printf("#");

			}
			printf("\n");
		}
		printf("\n");
	}
}