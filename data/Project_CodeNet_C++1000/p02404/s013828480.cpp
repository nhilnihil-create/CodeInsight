#include <stdio.h>

int main(){
	int H,W;
	int x,y;
	while(1){
		scanf("%d%d",&H,&W);
		if(H==0 && W==0){break;}
		for(x=0;x<H;x++){
			for(y=0;y<W;y++){
				if(x>0 && x<H-1 && y>0 && y<W-1){
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
	return 0;
}