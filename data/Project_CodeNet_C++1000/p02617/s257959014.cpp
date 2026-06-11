#include <bits/stdc++.h>

using namespace std;

typedef long long lli;

const int N = 200000 + 10;

struct Node
{
	lli sum, add;
};

vector<int> G[N];
int cntl[N], cntr[N];
Node stree[N*4];

void push_up(int index)
{
	stree[index].sum = stree[index*2].sum + stree[index*2+1].sum;
}

void push_down(int index, int begin, int end)
{
	int mid = (begin + end) / 2;
	stree[index*2].add += stree[index].add;
	stree[index*2].sum += 1LL * (mid - begin + 1) * stree[index].add;
	stree[index*2+1].add += stree[index].add;
	stree[index*2+1].sum += 1LL * (end - mid) * stree[index].add;
	stree[index].add = 0;
}

void update(int index, int begin, int end, int left, int right, int x)
{
	int mid;
	if (left <= begin && right >= end)
	{
		stree[index].add += x;
		stree[index].sum += 1LL * (end - begin + 1) * x; 
		return;
	}
	if (stree[index].add) push_down(index, begin, end);
	mid = (begin + end) / 2;
	if (right <= mid) update(index * 2, begin, mid, left, right, x);
	else if (left > mid) update(index * 2 + 1, mid + 1, end, left, right, x);
	else
	{
		update(index * 2, begin, mid, left, mid, x);
		update(index * 2 + 1, mid + 1, end, mid + 1, right, x);
	}
	push_up(index);
}

int main()
{
	lli res;
	int n, u, v, i, j;
	scanf("%d", &n);
	for (i=0; i<n-1; i++)
	{
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		if (v < u) cntl[u] ++; else cntr[u] ++;
		G[v].push_back(u);
		if (u < v) cntl[v] ++; else cntr[v] ++;
	}
	res = 0;
	update(1, 1, n, 1, n, 1);
	for (i=n-1; i>=1; i--) update(1, 1, n, 1, i, cntl[i+1] - 1);
	res += stree[1].sum;
	for (i=1; i<n; i++)
	{
		update(1, 1, n, i, n, cntr[i] - 1);
		for (j=0; j<G[i].size(); j++)
		{
			u = G[i][j];
			if (u > i) 
			{
				cntl[u] --;
				update(1, 1, n, i, u - 1, -1);
			}
		}
		res += stree[1].sum;
	}
	printf("%lld\n", res);
	return 0;
}