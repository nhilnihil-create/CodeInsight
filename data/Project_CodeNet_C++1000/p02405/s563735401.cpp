#include<stdio.h>
main(){
	int W,H;
	int i,j;

	while(1){
	scanf("%d %d",&W,&H);
	if(W == 0 && H == 0) break;
	for(i=1;i<=W;i++){
		for(j=1;j<=H;j++){
			if((i+j)%2 == 0){
				printf("#");
			}
			else{
				printf(".");
			}
		}
		printf("\n");
	}
	printf("\n");
	}

	return 0;
}