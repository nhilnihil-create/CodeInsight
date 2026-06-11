#include <iostream>
#include <cstdio>

using namespace std;

int main() {

	while (1) {
		int h, w;
		cin >> h >> w;
		if (h == 0 && w == 0) {
			break;
		}
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if ((x+y) % 2 == 0) {
					printf("#");
				}
				else {
					printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}