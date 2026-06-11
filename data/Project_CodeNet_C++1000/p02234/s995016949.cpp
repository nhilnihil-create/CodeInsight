#include <stdio.h>

int main() {	
	int rankN;
	int colRowL[101];
	int min[100][100];
	int left, right;
	int temp;
	int i, j, k;

	scanf("%d", &rankN);
	for (i = 0; i < rankN; i++) {
		scanf("%d %d", &colRowL[i], &colRowL[i + 1]);
	}

	for (i = 0; i < rankN; i++) {
		min[i][i] = 0;
	}
	for (i = 1; i < rankN; i++) {
		for (j = 0; j < rankN - i; j++) {
			left = j;
			right = j + i;
			min[left][right] = 1000000000;

			for (k = left; k < right ; k++) {
				temp = min[left][k] + min[k + 1][right] 
		                    +colRowL[left] * colRowL[k + 1] * colRowL[right + 1];
				if (temp < min[left][right]) {
					min[left][right] = temp;
				}
			}
		}
	}

	printf("%d\n", min[0][rankN - 1]);

	return 0;
}