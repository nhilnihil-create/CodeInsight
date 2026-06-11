#include<stdio.h>
int main(){
	int a[3][3];
	int c, b;
	int bingo[3][3] = {0};

	
	for(int i = 0;i < 3;i++){
		for(int j = 0; j < 3;j++){
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d", &c);
	printf("\n");
	for(int z =0;z < c;z++){
		scanf("%d", &b);
		for(int i = 0; i < 3;i++){
			for(int j = 0;j <3;j++){
				if(a[i][j] == b){
					bingo[i][j] = 1;
				}
			}
		}
	}
	
	if(bingo[0][0]+bingo[1][1]+bingo[2][2]==3||bingo[0][2]+bingo[1][1]+bingo[2][0]==3){
		printf("Yes");
		return 0;
	}for(int i = 0; i < 3;i++){
	if(bingo[i][0]+bingo[i][1]+bingo[i][2]==3||bingo[0][i]+bingo[1][i]+bingo[2][i]== 3){
		printf("Yes");
		return 0;
	}
}
printf("No");
return 0;
}