#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define M_PI 3.141592653589793


int main(void) {

	int i = 0, j, k;
	int sum;
	char fin[2] = "0";

	char str[1000][10000];

	while (1) {
		scanf("%s", str[i]);
		//printf("%d,%d\n", strlen(str[i]), atoi(str[i]));
		if ((int)strlen(str[i]) == 1 && (int)atoi(str[i]) == 0) {
			break;
		}
		i++;
	}
	

	for (j = 0; j < i; j++) {
		sum = 0;
		for (k = 0; k < strlen(str[j]); k++) {
			sum += str[j][k] - '0';
		}
		printf("%d\n", sum);
	}
	

	return 0;

}