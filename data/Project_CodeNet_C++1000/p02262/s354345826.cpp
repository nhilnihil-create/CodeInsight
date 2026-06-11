#include<iostream>
#include<cstdio>
using namespace std;

int m = 0, cnt = 0, G[100];

void shellSort(int a[], int n) {
	int i, j;
	cnt = 0;
	G[0] = 1;
	while (1) {
		G[m + 1] = 3 * G[m] + 1;
		if (G[m + 1] >= n)break;
		else m++;
	}
	m++;
	for (i = m - 1; i >= 0; i--) {
		int k, j, tmp;
		for (k = G[i]; k < n; k++) {
			tmp = a[k];
			j = k - G[i];
			while (j >= 0 && a[j] > tmp) {
				a[j + G[i]] = a[j];
				j -= G[i];
				cnt++;
			}
			a[j + G[i]] = tmp;
		}
	}
}


int main() {
	int i, j, n, a[1000000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	shellSort(a, n);
	printf("%d\n", m);
	for (i = m - 1; i >= 0; i--) {
		printf("%d", G[i]);
		if (i != 0)printf(" ");
		else printf("\n");
	}

	printf("%d\n", cnt);

	for (i = 0; i < n; i++) {
		printf("%d\n", a[i]);
	}

	return 0;
}