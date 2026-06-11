#define _USE_MATH_DEFINES

#include<math.h>
#include<stdio.h>
#include<utility>
#include<algorithm>

int main() {
	int H, W, n, m;
	n = 1;
	m = 1;
	while (true) {
		scanf("%d %d", &H, &W);

		if (H + W == 0) {
			break;
		}
		else {
			while (n <= H) {
				while (m <= W) {
					printf("#");
					m++;
				}
				printf("\n");
				n++;
				m = 1;
			}
			printf("\n");
			n = 1;
		}
	}
	return 0;
}