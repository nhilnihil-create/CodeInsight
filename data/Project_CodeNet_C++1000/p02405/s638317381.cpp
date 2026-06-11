#include<stdio.h>

int main(void){
	int W,H,a,b,c;
	while(1){
		scanf("%d %d",&H,&W);
		c = 0;
		if(W == 0 && H == 0){
			break;
		}
		for(b=0;b<H;b++){
			for(a=0;a<W;a++){
				if(c==0){
					printf("#");
					c = 1;
				}else{
					printf(".");
					c = 0;
				}
			}
			if(W%2==0){
				if(c==0){
					c = 1;
				}else{
					c = 0;
				}
			}
			printf("\n");
		}
		printf("\n");
	}


	return 0;
}