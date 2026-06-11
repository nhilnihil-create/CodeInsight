#include <stdio.h>

int main(){

	int H[100], W[100];
	int i, j, k,p;
	for (k = 0;; k++){
		scanf("%d %d", &H[k], &W[k]);
		if (H[k] == 0 && W[k] == 0)
			break;
	}

	for (p = 0; p < k; p++){
		for (i = 0; i < H[p]; i++){
			for (j = 0; j < W[p]; j++){
				if (i!=0&&i!=H[p]-1&&j!=0&&j!=W[p]-1){ 
					printf(".");
				}
				else{
					printf("#");
				}
				
			}
			printf("\n");
		}
		
			printf("\n");
		
	}
}