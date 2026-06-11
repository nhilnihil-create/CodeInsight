#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

#define MAX 256

int main(void){
	int n, m;

	scanf("%d%d", &n, &m);

	int a[n][m] = { 0 };
	int b[m] = { 0 };
	int c[n] = { 0 };

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < m; i++){
		scanf("%d", &b[i]);
	}

	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			c[i] += a[i][j] * b[j];
		}
	}

	for (int i = 0; i < n; i++){
		printf("%d\n", c[i]);
	}

	return 0;
}