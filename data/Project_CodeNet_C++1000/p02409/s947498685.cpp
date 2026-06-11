#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

#define MAX 256

int main(void){
	int n;

	scanf("%d", &n);

	int A[4][3][10] = { 0 };
	int b, f, r, v;

	for (int i = 0; i < n; i++){
		scanf("%d%d%d%d", &b, &f, &r, &v);
		A[b - 1][f - 1][r - 1] += v;
	}

	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 10; k++){
				printf(" %d", A[i][j][k]);
			}
			printf("\n");
		}
		if (i != 3){
			for (int l = 0; l < 20; l++){
				printf("#");
			}
			printf("\n");
		}
	}

	return 0;
}