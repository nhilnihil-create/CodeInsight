#include <stdio.h>

int main(void){

	int width,height,wcount;

	while(1){
		scanf("%d",&height);
		scanf("%d",&width);
		
		if(height==0&&width==0){
			break;
		}
		
		while(height>0){
			for(wcount=width;wcount>0;wcount--){
				printf("#");
			}
			printf("\n");
			height--;
		}
		
		printf("\n");
	}
		
	return 0;
}