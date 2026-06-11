#include<stdio.h>
int main(void){

int H,W,i,t;

for(;;){
scanf("%d %d",&H,&W);

if(H==0&&W==0){
break;
}


	for(i=1;i<=H;i++){
		printf("#");
		for(t=3;t<=W;t++){
			if(i==1||i==H){
				printf("#");
			}else{
				printf(".");
			}
		}
		printf("#");
		printf("\n");
	}
	printf("\n");
}

 return 0;
}