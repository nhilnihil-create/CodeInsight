#include <stdio.h>

int main() {
	int x, b, bingo[3][3] = {};
	bool bing[3][3] = {false};
	
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			scanf("%d", &bingo[i][j]);
		}
	}
	scanf("%d", &x);
	for(int i = 0; i < x; i++) {
		scanf("%d", &b);
		for(int j = 0; j < 3; j++) {
			for(int k = 0; k < 3; k++) {
				if(b == bingo[j][k]) {
					bing[j][k] = true;
				}
			}
		}
	}
	
	if(bing[0][0] && bing[0][1] && bing[0][2] || bing[0][0] && bing[1][0] && bing[2][0]) {
		printf("Yes");
	} else if(bing[1][0] && bing[1][1] && bing[1][2] || bing[0][1] && bing[1][1] && bing[2][1]) {
		printf("Yes");
	} else if(bing[2][0] && bing[2][1] && bing[2][2] || bing[0][2] && bing[1][2] && bing[2][2]) {
		printf("Yes");
	} else if(bing[0][0] && bing[1][1] && bing[2][2] || bing[0][2] && bing[1][1] && bing[0][2]) {
		printf("Yes");
	} else {
		printf("No");
	}
	
	return 0;
}