#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <complex>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack> 
#include <bitset>
#include <queue>
#include <assert.h>
#include <unordered_map>
using namespace std;

const int N = 200010;
vector<int> v[N];
int pre[N];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}

	queue<int> q;
	q.push(1);
	memset(pre, -1, sizeof(pre));
	pre[1] = 0;
	int tot = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		tot++;
		for (int i = 0; i < v[u].size(); i++) {
			int x = v[u][i];
			if (pre[x] == -1) {
				q.push(x);
				pre[x] = u;
			}
		}
	}

	if (tot < n) {
		printf("No\n");
		return 0;
	}

	printf("Yes\n");
	for (int i = 2; i <= n; i++)
		printf("%d\n", pre[i]);
	return 0;
}
