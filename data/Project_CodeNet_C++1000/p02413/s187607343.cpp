#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

#define MAX 256

int main(void){
	
	int r, c;

	scanf("%d%d", &r, &c);
	
	int a[r + 1][c + 1] = { 0 };

	for (int i = 0; i <= r; i++){
		for (int j = 0; j <= c; j++){
			a[i][j] = 0;
		}
	}

	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			a[i][c] += a[i][j];
		}
	}

	for (int i = 0; i < c; i++){
		for (int j = 0; j < r; j++){
			a[r][i] += a[j][i];
		}
	}

	for (int i = 0; i < r; i++){
		a[r][c] += a[i][c];
	}

	for (int i = 0; i <= r; i++){
		for (int j = 0; j < c; j++){
			printf("%d ", a[i][j]);
		}
		printf("%d\n", a[i][c]);
	}

	return 0;
}