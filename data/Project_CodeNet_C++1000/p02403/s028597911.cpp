#include<stdio.h>

int main(){

	int i, j, height, width;

	while(1){
		scanf("%d %d", &height, &width);

		if(height == 0 && width == 0){
			break;
		}

		for(i = 0; i < height; i++){
			for (j = 0; j < width - 1; j++){
				printf("#");
			}
			printf("#\n");
		}
		printf("\n");
	}

	return 0;

}