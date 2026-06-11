#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;
int main()
{
	int i, j, m, n, cnt = 0, cnt1 = 0;
	char str[602];
	for (i = 0; i < 300; i = i + 2) {
		str[i] = '#';
		str[i + 1] = '.';
	}
	while (1) {
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0) {
			break;
		}
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (i % 2 == 0) {
					printf("%c", str[j]);
				}
				else {
					printf("%c", str[j + 1]);

				}
				if (j == j - 1) {
					printf(" ");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	}