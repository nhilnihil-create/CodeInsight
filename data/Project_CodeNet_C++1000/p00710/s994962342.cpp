#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int input(char s[]);

int main() {
	int n, r, brk = 0, p, c, x[50], xs[50];
	
	while (1) {
		for (int i = 0; i < 50; i++)
			x[i] = xs[i] = i;
		scanf("%d %d", &n, &r);
		if (n == 0 && r == 0)
			break;
		for (int i = 0; i < r&&brk == 0; i++) {
			scanf("%d %d", &p, &c);
			for (int j = 0; j < c; j++)
				x[j] = xs[j + p - 1];
			for (int j = c; j < c + p - 1; j++)
				x[j] = xs[j - c];
			for (int j = 0; j < n; j++)
				xs[j] = x[j];
			/*for (int j = n-1; j >=0; j--) {
				printf("%2d  %2d\n",j, x[j]);
			}*/
		}
		printf("%d\n", n - x[0]);
	}
	return 0;
}
