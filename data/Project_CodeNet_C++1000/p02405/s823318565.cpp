#include <cstdio>

int main() {
	int h, w;
	while (1) {
		scanf("%d %d", &h, &w);
		if (!h && !w) break;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				putchar(!((i + j) % 2) ? '#' : '.');
			}
			puts("");
		}
		puts("");
	}
}