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

	for (int j = 0; j < i; j++){
		for (int k = 0; k < h[j]; k++){
			for (int l = 0; l < w[j]; l++){
				printf("#");
			}
			printf("\n");
		}
		if (j != i - 1)printf("\n");
	}

	return 0;
}