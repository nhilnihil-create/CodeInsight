#include <stdio.h>

int main(){
	
	int matrix[3][3];
	int bingo [3][3] = {0};
	
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	
	int N;
	scanf("%d", &N);
	
	for(int k=0; k<N; k++){
		int a;
		scanf("%d", &a);
		for(int i= 0; i<3; i++){
			for(int j = 0; j<3; j++){
				if(matrix[i][j] == a){
					bingo[i][j] = 1;
				}
			}
		}
	}
	
	if(bingo[0][0] + bingo[1][1] + bingo[2][2] == 3 || bingo[0][2] +bingo[1][1] +bingo[2][0] == 3){
		printf("Yes\n");
		return 0;
	}for(int i = 0; i < 3;i++){
	if(bingo[i][0]+bingo[i][1]+bingo[i][2]==3||bingo[0][i]+bingo[1][i]+bingo[2][i]== 3){
		printf("Yes\n");
		return 0;
	}
}
printf("No\n");	
	return 0;
}