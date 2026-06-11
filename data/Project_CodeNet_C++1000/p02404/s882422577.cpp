#include <stdio.h>

int main(void){

	int H,W,h,w;

	for(;;){

	scanf("%d %d",&H,&W);

	for(h=0;h<H;h++){
		for(w=0;w<W;w++){
			if(h==0||h+1==H||w==0||w+1==W){
				printf("#");
			}
			else{
				printf(".");
			}
		}
		printf("\n");
	


	}
		if(W==0&&H==0){
		break;
	}

	printf("\n");
	}
	

	return 0;
}