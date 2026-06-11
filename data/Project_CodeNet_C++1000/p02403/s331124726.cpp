#include<stdio.h>
int main(){
	int H,W;
	while(1){
		scanf("%d %d",&H,&W);
		if(H==0&&W==0){
			break;
		}
		for(int x=0;x<H;x++){
			for(int y=0;y<W;y++){
				printf("#");
			}
printf("\n");
		}
		printf("\n");
	}
	return 0;
}