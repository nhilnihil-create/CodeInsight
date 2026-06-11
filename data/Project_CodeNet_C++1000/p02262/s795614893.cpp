#include <stdio.h>
using namespace std;
int G[1500000];
long long cnt = 0;
void insertionSort(int*p, int n, int g) {
	for (int i = g; i < n; i++) {
		int v = p[i];
		int j = i - g;
		while (j >= 0 && p[j] > v) {
			p[j + g] = p[j];
			j -= g;
			cnt++;
		}
		p[j + g] = v;
	}
}
void shellSort(int*p, int n) {
	int  x = 0, zlq = n;
	while (zlq>0)
	{
		G[x] = zlq >> 1;
		zlq = zlq >> 1;
		x++;
	}
	x--;
	if (x == 0)
	{
		printf("1\n1\n0\n1\n");
		return;
	}
	for (int i = 0; i < x; i++)insertionSort(p, n, G[i]);
	printf("%d\n", x);
	for (int i = 0; i < x; i++)printf("%d ", G[i]);
	printf("\n");
}
int main()
{
	int n;
	int*seq;
	scanf("%d", &n);
	seq = new int[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &seq[i]);

	shellSort(seq, n);
	if (n == 1)return 0;
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++)
		printf("%d\n", seq[i]);

	return 0;
}