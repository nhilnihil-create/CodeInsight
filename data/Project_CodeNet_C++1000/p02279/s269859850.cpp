
#include <iostream>
#include <cstdio>
#include <algorithm>
#include<cstring>
#include <stack>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include <string>
const int MAXN = 2000 * 100 + 6;
typedef long long LL;
int t, n, m;
using namespace std;
struct node {
	int parent = -1;
	int depth = 0;
	vector<int>child;
}tree[MAXN];
void dfs(node &root) {
	for (auto it : root.child) {
		tree[it].depth = root.depth + 1;
		dfs(tree[it]);
	}
}
int main()
{
#ifdef _DEBUG
	freopen("E:\\input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
#endif
	int i, j;
	LL ans;
	scanf("%d", &n);
	int root = 0;
	for (int i = 0; i < n; i++) {
		int id, numofchild;
		scanf("%d %d", &id, &numofchild);

		for (int j = 0; j < numofchild; j++) {
			int child;
			scanf("%d", &child);
			tree[id].child.push_back(child);
			tree[child].depth = tree[id].depth + 1;
			tree[child].parent = id;
		}
		if (tree[id].depth == 0)root = id;
	}
	dfs(tree[root]);
	for (int i = 0; i < n; i++) {
		printf("node %d: parent = %d, depth = %d, ", i, tree[i].parent, tree[i].depth);
		if (tree[i].depth == 0)printf("root");
		else if (tree[i].child.size() == 0)printf("leaf");
		else printf("internal node");
		printf(", [");
		int j = 0;
		for (auto it : tree[i].child) {
			if (j++)printf(", ");
			printf("%d",it);
		}
		printf("]\n");
	}
	return 0;
}
