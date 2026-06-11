#include <stdio.h>

int main() {
	int arr[3][3], bingo = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int n;
	scanf("%d", &n);
	while (n--) {
		int b, sumVert = 0, sumHor = 0, prim = 0, sec = 0;
		scanf("%d", &b);
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				arr[i][j] == b ? arr[i][j] = 0 : arr[i][j] = arr[i][j];
			}
		}
		for (int i = 0; i < 3; i++) {
			sumVert = sumHor = 0;
			for (int j = 0; j < 3; j++) {
				sumVert += arr[j][i];
				sumHor += arr[i][j];
			}
			bingo = sumVert == 0 || sumHor == 0 ? 1 : bingo;
		}
		for (int i = 0, j = 2; i < 3; i++, j--) {
			prim += arr[i][i];
			sec += arr[i][j];
		}
		bingo = prim == 0 || sec == 0 ? 1 : bingo;
	}
	bingo ? puts("Yes") : puts("No");
	return 0;
}