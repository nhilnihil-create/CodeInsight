#include<stdio.h>

int main () {
	int matrix[3][3];
	char x;
	
	for (int i = 0 ; i < 3 ; i++) {
		for (int j = 0 ; j < 3 ; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	int n;
	scanf("%d", &n);
	int angka[n];
	
	for (int i = 0 ; i < n ; i++) {
		scanf("%d", &angka[i]);
		for (int j = 0 ; j < 3 ; j++) {
			for (int k = 0 ; k < 3 ; k++) {
				if (angka[i] == matrix[j][k]) {
					matrix[j][k] = x;
				}	
			}
		}
	}
	
	int counter[8] = {0};
	int akhir = 2;
	for (int i = 0 ; i < 3 ; i++) {
		if(matrix[i][0] == x)  {
			++counter[0];
		}
		if(matrix[i][2] == x) {
			++counter[1];
		}
		if(matrix[0][i] == x) {
			++counter[2];
		}
		if(matrix[2][i] == x) {
			++counter[3];
		}
		if(matrix[i][i] == x) {
			++counter[4];
		}
		if(matrix[i][akhir--] == x) {
			++counter[5];
		}
		if(matrix[1][i] == x) {
			++counter[6];
		}
		if(matrix[i][1] == x) {
			++counter[7];
		}
	}
	int flag = 0;
	for(int i = 0 ; i < 8 ; i++) {
		if(counter[i] == 3) {
			flag = 1;
		}
	}
	printf("%s\n", (flag == 1) ? "Yes" : "No") ;
	return 0;
}