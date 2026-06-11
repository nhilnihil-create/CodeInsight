#include<stdio.h>

int main(){

	int i, j, height, width;

	while(1){
		scanf("%d %d", &height, &width);

		if(height == 0 && width == 0){
			break;
		}

		for(i = 0; i < height; i++){
			if(i % 2 == 0){
				for (j = 0; j < width; j++){
					if(j % 2 == 0){
						printf("#");
					} else {
						printf(".");
					}
				}
			} else {
				for (j = 0; j < width; j++){
					if(j % 2 == 1){
						printf("#");
					} else {
						printf(".");
					}
				}
			}

			printf("\n");
		}
		printf("\n");
	}

	return 0;

}