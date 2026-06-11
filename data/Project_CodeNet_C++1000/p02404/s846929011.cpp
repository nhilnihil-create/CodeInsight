#include<stdio.h>
main(){
	int H,W;
	int i,j;

	while(1){
		scanf("%d %d",&H,&W);
		if(H == 0 && W == 0) break;
		for(i=1;i<=W;i++){
			printf("#");
		}
		printf("\n");
		for(i=2;i<=H-1;i++){
			printf("#");
			for(j=2;j<=W-1;j++){
				printf(".");
			}
			printf("#\n");
		}
		for(i=1;i<=W;i++){
			printf("#");
		}
		printf("\n");
		printf("\n");
	}
	return 0;
}