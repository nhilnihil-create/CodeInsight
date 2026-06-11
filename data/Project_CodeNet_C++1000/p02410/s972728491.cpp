#include <stdio.h>

int main(){

	int vecA[100][100] = { 0 };
	int vecB[100] = { 0 };
	int vecC[100] = { 0 };
	int x, y;
	int i, j;
	scanf("%d %d", &x, &y);

	for (i = 0; i < x; i++){
		for (j = 0; j < y; j++){
			scanf("%d", &vecA[i][j]);
		}
	}
	for (j = 0; j < y; j++){
		scanf("%d", &vecB[j]);
	}

	for (i = 0; i < x; i++){
		for(j = 0; j < y; j++ ){
			vecC[i] = vecC[i] +( vecA[i][j] * vecB[j]);
		}
		printf("%d\n", vecC[i]);
	}
	
}