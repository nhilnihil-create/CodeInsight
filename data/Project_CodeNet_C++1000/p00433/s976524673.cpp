#include <cstdio>

int main(void) {
	int score[2] = { 0 };
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			int buf;
			scanf("%d", &buf);
			score[i] += buf;
		}
	}
	
	printf("%d\n", score[0] > score[1] ? score[0] : score[1]);
	return 0;
}