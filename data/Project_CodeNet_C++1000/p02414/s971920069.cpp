#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int n, m, l;
	int A[101][101], B[101][101];

	scanf("%d %d %d", &n, &m, &l);

	int v;
	int i, j;

	for(i = 0; i < 101; i++) {
		for(j = 0; j < 101; j++) {
			A[i][j] = 0;
			B[i][j] = 0;
		}
	}

	for(i = 0; i < n; i++) {
		j = 0;
		while(cin >> v) {
			A[i][j] = v;
			//printf("A[%d][%d] = %d\n", i, j, v);
			j++;
			if(j >= m) break;
		}
	}

	for(i = 0; i < m; i++) {
		j = 0;
		while(cin >> v) {
			B[i][j] = v;
			//printf("B[%d][%d] = %d\n", i, j, v);
			j++;
			if(j >= l) break;
		}
	}

	long int c;
	int k;
	for(i = 0; i < n; i++) {
		for(j = 0; j < l; j++) {
			c = 0;
			for(k = 0; k < m; k++) {
				c += A[i][k] * B[k][j];
			}
			printf("%ld", c);
			if(j < l - 1) printf(" ");
			else printf("\n");
		}
	}

	return 0;
}