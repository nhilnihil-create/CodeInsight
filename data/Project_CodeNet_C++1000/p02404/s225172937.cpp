#include<stdio.h>

int main(void){
int H,W,i,I,j;
for(j=0;j<10000;j++){
	scanf("%d %d",&H,&W);
	if(H!=0){
	for(i=0;i<H;i++){
		if(i==0||i==H-1){
		
			for(I=0;I<W;I++){
			printf("#");
		}
				printf("\n");
	}else{
		for(I=0;I<W;I++){
			if(I==0||I==W-1){
			printf("#");	
			}else{
					printf(".");
			}
			
	}
	printf("\n");
	}
	}
	}else{
	break;
		}

	printf("\n");


			
		}
	
	return 0;
}
