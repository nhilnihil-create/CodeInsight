#include<stdio.h>

int main(){

	int i, j, height, width;

	while(1){
		scanf("%d %d", &height, &width);

		if(height == 0 && width == 0){
			break;
		}

		for(i = 0; i < width; i++){
			printf("#");
		}

		printf("\n");

		for(i = 0; i < height - 2; i++){
			printf("#");
			for (j = 0; j < width - 2; j++){
				printf(".");
			}
			printf("#\n");
		}
		
		for(i = 0; i < width; i++){
			printf("#");
		}

		printf("\n");

		printf("\n");
	}

	return 0;

}