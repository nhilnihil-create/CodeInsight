#include <cstdio>

int main() {
	int w, h;
	while(true) {
		scanf("%d %d", &h, &w);
		if(w == 0 & h == 0) break;
		for(int i = 1; i <= w*h; i++) {
			printf("#");
			if(i % w == 0) printf("\n");
		}
		printf("\n");
	}
	return 0;
}