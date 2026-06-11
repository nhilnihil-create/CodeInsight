#include <iostream>
#include <algorithm>
#include <cstdio>
#include <list>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <ostream>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <iomanip>

#define N 100005
#define INF (1 << 30)
#define NIL -1
using namespace std;
struct Node { int parent, child, sibling; } T[N];
int depth[N];
void setDepth(int root, int d)
{
	depth[root] = d;
	if (T[root].child != NIL)
		setDepth(T[root].child, d + 1);
	if (T[root].sibling != NIL)
		setDepth(T[root].sibling, d);
}
const char *str[3] = { "root", "leaf", "internal node" };
void print(int id)
{
	int status = 0;
	if (T[id].parent == NIL)
		status = 0;
	else if (T[id].child == NIL)
		status = 1;
	else
		status = 2;
	printf("node %d: parent = %d, depth = %d, %s, [", id, T[id].parent, depth[id], str[status]);
	for (int i = 0, child = T[id].child; child != NIL; ++i, child = T[child].sibling)
	{
		if (i)
			printf(", ");
		printf("%d", child);
	}
	printf("]\n");
}


int main()
{
	int n, id, k, child;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		T[i].parent = T[i].child = T[i].sibling = NIL;
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &id, &k);
		for (int j = 0, pre = 0; j < k; ++j)
		{
			scanf("%d", &child);
			if (j == 0)
				T[id].child = child;
			else
				T[pre].sibling = child;
			pre = child;
			T[child].parent = id;
		}
	}
	int root = NIL;
	for (int i = 0; i < n; ++i)
	{
		if (T[i].parent == NIL)
		{
			root = i;
			break;
		}
	}
	setDepth(root, 0);
	for (int i = 0; i < n; ++i)
		print(i);
	return 0;
}