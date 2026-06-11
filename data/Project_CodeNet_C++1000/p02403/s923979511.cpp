#include <cstdio>

int main() {
	int h, w;
	while (1) {
		scanf("%d %d", &h, &w);
		if (!h && !w) break;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				putchar('#');
			}
			puts("");
		}
		puts("");
	}
}