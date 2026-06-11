#include <stdio.h>

int main() {
	int trix1[4][4], Zx, Xy;
		for (int u = 0; u < 3; u++) {
			for (int i = 0; i < 3; i++) {
				scanf("%d", &trix1[u][i]);
			}
		}
		int trix2[4][4] = {};
		scanf("%d", &Zx);
		for(int o = 0; o < Zx; o++) {
			scanf("%d", &Xy);
			for (int u = 0; u < 3; u++) {
				for (int i = 0; i < 3; i++) {
					if (Xy == trix1[u][i]) {
						trix2[u][i]++;
					  	if ((trix2[0][0] > 0 && trix2[0][1] > 0 && trix2[0][2] > 0) || (trix2[1][0] > 0 && trix2[1][1] > 0 && trix2[1][2] > 0) || (trix2[2][0] > 0 && trix2[2][1] > 0 && trix2[2][2] > 0) || (trix2[0][0] > 0 && trix2[1][0] > 0 && trix2[2][0] > 0) || (trix2[0][1] > 0 && trix2[1][1] > 0 && trix2[2][1] > 0) || (trix2[0][2] > 0 && trix2[1][2] > 0 && trix2[2][2] > 0) || (trix2[0][2] > 0 && trix2[1][1] > 0 && trix2[2][0] > 0) || (trix2[0][0] > 0 && trix2[1][1] > 0 && trix2[2][2] > 0)) {
					  		printf("Yes\n");
					  		return 0;
					  	}
					}
				}
			}
		}
	printf("No\n");
	return 0;
}