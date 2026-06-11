#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 5;
struct node
{
	int x, y, px, py;
}p[N];
bool cmp(node a, node b)
{
	return a.px < b.px;
}
bool dmp(node a, node b)
{
	return a.py < b.py;
}
int n, maxn = 0;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d%d", &p[i].x, &p[i].y);
		p[i].px = p[i].x + p[i].y;
		p[i].py = p[i].y - p[i].x;
	}
	sort(p + 1, p + n + 1, cmp);
	maxn = p[n].px - p[1].px;
	sort(p + 1, p + n + 1, dmp);
	maxn = max(maxn, p[n].py - p[1].py);
	printf("%d", maxn); 
	return 0;
} 