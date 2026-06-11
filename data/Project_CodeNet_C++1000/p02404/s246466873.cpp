#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

#define MAX 256

int main(void){
	int h[MAX], w[MAX];
	int i = 0, t = 1;
	while (t == 1){
		scanf("%d %d", &h[i], &w[i]);
		if (h[i] == 0 && w[i] == 0)t = 0;
		i++;
	}

	for (int j = 0; j < i-1; j++){
		for (int l = 0; l < w[j]; l++){
			printf("#");
		}
		printf("\n");
		for (int k = 1; k < h[j] - 1; k++){
			printf("#");
			for (int l = 1; l < w[j] - 1; l++){
				printf(".");
			}
			printf("#\n");
		}
		for (int l = 0; l < w[j]; l++){
			printf("#");
		}
		printf("\n");
		if (j != i - 1)printf("\n");
	}

	return 0;
}