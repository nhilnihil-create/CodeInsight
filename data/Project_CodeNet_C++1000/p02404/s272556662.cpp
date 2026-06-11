#include <cstdio>

int main() {
	int h, w;
	while(true) {
		scanf("%d %d", &h, &w);
		if(h == 0 & w == 0) break;

		for(int i = 1; i <= h*w; i++) {
			if(i <= w | i % w == 0 | i > w*(h-1)+1) printf("#");
			else if(i % w == 1) {
				printf("\n");
				printf("#");
			}
				else printf(".");
		}
		printf("\n\n");
	}	
	return 0;
}