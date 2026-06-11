#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <string>
#define N 100005
#define INF (1 << 30)
typedef long long ll;
using namespace std;

vector<int> child[N];
int parent[N];
int GetDepth(int idx)
{
	if (parent[idx] == -1)
		return 0;
	return GetDepth(parent[idx]) + 1;
}
const char *str[3] = { "root", "internal node", "leaf" };
int main()
{
	int n;
	cin >> n;
	fill(parent, parent + n, -1);
	int id, k, c;
	for (int i = 0; i < n; ++i)
	{
		cin >> id >> k;
		for (int j = 0; j < k; ++j)
		{
			cin >> c;
			parent[c] = id;
			child[id].push_back(c);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		int depth = GetDepth(i);
		int status;
		if (depth == 0)
			status = 0;
		else if (child[i].size())
		{
			status = 1;
			sort(child[i].begin(), child[i].end());
		}
		else
			status = 2;
		printf("node %d: parent = %d, depth = %d, %s, ", i, parent[i], depth, str[status]);
		printf("[");
		for (int j = 0; j < child[i].size(); ++j)
		{
			if (j)
				printf(", ");
			printf("%d", child[i][j]);
		}
		printf("]\n");
	}
	return 0;
}