#include <stdio.h>
#include <stdlib.h>
int main() {
	
	int arr1[3][3];
	int N, a,x;
	int arr2[3][3] = {0};
	
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			scanf("%d", &arr1[i][j]);
		}
	}
	
	scanf("%d", &N);
	
	for(int a = 0; a < N; a++){
			scanf("%d", &x);
			for(int i = 0; i < 3; i++){
				for(int j= 0; j < 3; j++){
					if(arr1[i][j] == x){
						arr2[i][j] = 1;
					}
				}
		}
	}
	
	if(arr2[0][0] + arr2[1][1] + arr2[2][2] == 3
		|| arr2[0][2] + arr2[1][1] + arr2[2][0] == 3){
		printf("Yes\n");
		return 0;
	}
	
	for(int i = 0; i < 3; i++){
		if(arr2[i][0] + arr2[i][1] + arr2[i][2] == 3
			|| arr2[0][i] + arr2[1][i] + arr2[2][i] == 3){
			printf("Yes\n");
			return 0;
		}
	}
	
	printf("No");
	
	return 0;
}