#include <cstdio>

int main(int argc, char *argv[]) {
	
	while (true) {
		int player1[4];
		int player2[4];
		int hit = 0, blow = 0;
		
		if (EOF == fscanf(stdin, "%d %d %d %d\n",
			 &player1[0], &player1[1], &player1[2], &player1[3])) {
			break;
		}
		fscanf(stdin, "%d %d %d %d\n", &player2[0], &player2[1],
			&player2[2], &player2[3]);
		
		for (int i = 0; i < 4; i++) {
			// hit
			if (player1[i] == player2[i]) {
				hit++;
			}
			// blow
			for (int j = 0; j < 4; j++) {
				if (i != j) {
					if (player1[i] == player2[j]) {
						blow++;
					}
				}
			}
		}
		printf("%d %d\n", hit, blow);
	}
	return 0;
}