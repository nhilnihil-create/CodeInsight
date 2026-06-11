#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int H, W;

int flame(int h, int w)
{
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (i == 0 || i == h - 1 || j == 0 || j == w - 1) {
				printf("#");
			}
			else {
				printf(".");
			}
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}

int main(){
	while (cin >> H >> W && (H | W) != 0) {
		flame(H, W);
	}

	return 0;
}