#include<stdio.h>
main(){
	int rooms[4][3][10];
	int num;
	int n1,n2,n3,n4;
	int i,j,k;

	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			for(k=0;k<10;k++){
				rooms[i][j][k] = 0;
			}
		}
	}

	scanf("%d",&num);

	for(i=1;i<=num;i++){
		scanf("%d %d %d %d",&n1,&n2,&n3,&n4);
		rooms[n1-1][n2-1][n3-1] += n4;
	}

	for(i=0;i<4;i++){
		for(j=0;j<3;j++){
			for(k=0;k<10;k++){
				printf(" %d",rooms[i][j][k]);
			}
			printf("\n");
		}
		if(i != 3){
			printf("####################\n");
		}
	}

	return 0;
}