#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
	int i, j, h, w, g;
	while (1) {
		cin >> h >> w;
		if (h == 0 && w == 0) {
			break;
		}
		for (i = 0; i < h; i++) {
			for (j = 0; j < w; j++) {
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
	}
}