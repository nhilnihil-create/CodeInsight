#include<stdio.h>
int main(){
	int matrix[3][3];
	char o;
	for(int i = 0; i<3 ; i++){
		for(int j = 0; j<3 ; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	int N;
	scanf("%d", &N);
	int input[N];
	for(int x = 0; x < N ; x++){
		scanf("%d", &input[x]);
		for(int i = 0 ; i<3 ; i++){
			for(int j = 0 ; j<3 ; j++){
				if(input[x] == matrix[i][j]){
					matrix[i][j] = o;
				}
			}
		}
	}
	int ctr[8] = {0};
	int last = 2;
	for(int i = 0; i<3; i++){
		if(matrix[i][0] == o){
			++ctr[0];
		}
		if(matrix[i][1] == o){
			++ctr[1];
		}
		if(matrix[i][2] == o){
			++ctr[2];
		}
		if(matrix[0][i] == o){
			++ctr[3];
		}
		if(matrix[1][i] == o){
			++ctr[4];
		}
		if(matrix[2][i] == o){
			++ctr[5];
		}
		if(matrix[i][i] == o){
			++ctr[6];
		}
		if(matrix[i][last--] == o){
			++ctr[7];
		}
	}
	int flag = 0;
	for(int i = 0; i < 8; i++){
		if(ctr[i] == 3){
			flag = 1;
		}
	}
	if(flag == 1){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	
	return 0;
}