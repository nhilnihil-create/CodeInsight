#include<cstdio>
int cnt;
void insertionSort(int *a, int n, int g) {
	int i, v, j;
	for (int i = g; i < n; i++) {
		v = a[i];
		j = i - g;
		while (j >= 0 && a[j] > v) {
			a[j + g] = a[j];
			j = j - g;
			cnt++;
		}
		a[j + g] = v;
	}
}
int a[1000000];
int main() {
	cnt = 0;
	int g = 1, i, n, m = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", &a[i]);
	while (g <= n)g = 3 * g + 1;
	while (true) {
		g = (g - 1) / 3;
		if (g == 0)break;
		m++;
		insertionSort(a, n, g);
	}
	g = 1;
	while (g <= n)g = 3 * g + 1;
	g = (g - 1) / 3;
	printf("%d\n%d", m, g);
	while (true) {
		g = (g - 1) / 3;
		if (g == 0)break;
		printf(" %d", g);
	}
	printf("\n%d\n", cnt);
	for (i = 0; i < n; i++)printf("%d\n", a[i]);
	return 0;
}
