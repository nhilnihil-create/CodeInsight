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
				if (i%2==0){ 
					if (j % 2 == 0){
						printf("#");
					}
					else{
						printf(".");
					}
				}
				else{
					if (j % 2 == 0){
						printf(".");
					}
					else{
						printf("#");
					}
				}
				
			}
			printf("\n");
		}
		
			printf("\n");
		
	}
}