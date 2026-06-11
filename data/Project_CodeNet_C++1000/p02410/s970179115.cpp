#include <stdio.h>
#include <math.h>

#define M_PI 3.141592653589793

int main(void) {

	int i, j, k, n;
	int a, b;
	int num;
	int matrix[100][100];
	int vector[100];

	scanf("%d %d", &a, &b);//???,???

	for (i = 0; i < a; i++) {
		for (j = 0; j < b; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	for (j = 0; j < b; j++) {
		scanf("%d", &vector[j]);
	}


	for (i = 0; i < a; i++) {
		num = 0;
		for (j = 0; j < b; j++) {
			num += matrix[i][j] * vector[j];
		}
		printf("%d\n", num);
	}


	return 0;

}