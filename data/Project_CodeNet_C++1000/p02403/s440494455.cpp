#include<stdio.h>
int main(void){
	int H,W,a,b,c=0;
	while(1){
		scanf("%d %d",&H,&W);
		if(c==1){printf("\n");}
		else{c=1;}
		for(a=0;a<H;a++){
			for(b=0;b<W;b++){
				printf("#");
			}
			printf("\n");
		}
		if(H==0&&W==0){
			break;}
	}
	return 0;

}