#include <stdio.h>

int main() {

	int mat[3][3];
	
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			scanf("%d", &mat[i][j]);
		}
	}		
	int c[3][3] = {};
	int a;
		
		scanf("%d", &a);
	
	int b;
		
	for(int i = 0; i < a; i++) {
		
		scanf("%d", &b);
	
	for(int j = 0; j < 3; j++) {
		for(int k = 0; k < 3; k++) {
			if(b == mat[j][k]) {
				c[j][k]++;
				
				if((c[0][0] > 0 && c[0][1] > 0 && c[0][2] > 0) || (c[1][0] > 0 && c[1][1] > 0 && c[1][2] > 0) || (c[2][0] > 0 && c[2][1] > 0 && c[2][2] > 0) || (c[0][0] > 0 && c[1][0] > 0 && c[2][0] > 0) || (c[0][1] > 0 && c[1][1] > 0 && c[2][1] > 0) || (c[0][2] > 0 && c[1][2] > 0 && c[2][2] > 0) || (c[0][2] > 0 && c[1][1] > 0 && c[2][0] > 0) || (c[0][0] > 0 && c[1][1] > 0 && c[2][2] > 0)) {
			printf("Yes");
			return 0;
				}
			}
		}
	}
}
printf("No");
	return 0;
}
