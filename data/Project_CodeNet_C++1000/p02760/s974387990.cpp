#include <stdio.h>
#include <string.h>

int main(){
	int box[3][3] = {0};
	int N, P;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			scanf("%d", &box[i][j]);
		}
	}
	
	int pick[3][3]={0};
	scanf ("%d", &N);
	for (int i=0; i<N; i++){
		scanf ("%d", &P);
		for (int i=0; i<3; i++){
			for (int j=0; j<3; j++){
				if (box[i][j]==P){
					pick[i][j]++;
				}
			}
		}
	} 
	
	// Bingo Down
	for (int i=0; i<3; i++){ 
		if (pick[i][0]>=1){
		if (pick[i][1]>=1){
		if (pick[i][2]>=1){
		printf ("Yes\n");
		return 0;
		}
		}
		}
	}
	
	//Bingo Across
	for (int i=0; i<3; i++){
		if (pick[0][i]>=1){
		if (pick[1][i]>=1){
		if (pick[2][i]>=1){
		printf ("Yes\n");
		return 0;
		}
		}
		}
	}
	
	//Bingo Diagonal 11 22 33
		if (pick[0][0]>=1){
		if (pick[1][1]>=1){
		if (pick[2][2]>=1){
		printf ("Yes\n");
		return 0;
		}
		}
		}
	
	
	//Bingo Diagonal 02, 11, 20
		if (pick[0][2]>=1){
		if (pick[1][1]>=1){
		if (pick[2][0]>=1){
		printf ("Yes\n");
		return 0;
		}
		}
		}
		
	printf("No\n");
	return 0;
}