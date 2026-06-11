#pragma warning(disable:4996)
#include <stdio.h>
#include <algorithm>
using namespace std;
int root[200200];
bool team[200200];
int n, m;
int find(int a)
{
	if (root[a] < 0) return a;
	else return root[a] = find(root[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return;
	root[a] += root[b];
	root[b] = a;
	return;
}
int main()
{
	scanf("%d %d", &n, &m);
	fill(root, root + n + 1, -1);
	for (int i = 1; i <= m; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		merge(a, b);
	}
	int max=0;
	for (int i = 1; i <= n; i++)
	{
		max = max > -root[i] ? max : -root[i];
	}
	printf("%d", max);
}