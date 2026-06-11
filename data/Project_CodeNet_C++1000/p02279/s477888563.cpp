#include <cstdio>
#include <vector>
using namespace std;

const int SIZE = 100000;
int n, k, c;
vector<int> ch[SIZE];
int par[SIZE], depth[SIZE];

void dfs(int id) {
	if (ch[id].empty()) return;
	for (int i = 0;i < ch[id].size();i++) {
		depth[ch[id][i]] = depth[id] + 1;
		dfs(ch[id][i]);
	}
}

int main() {
	int id, root;
	bool list;

	scanf("%d", &n);
	for (int i = 0;i < n;i++) {
		par[i] = -1;
		depth[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &id, &k);
		for (int i = 0;i < k;i++) {
			scanf("%d", &c);
			ch[id].push_back(c);
			par[c] = id;
		}
	}

	for (int i = 0;i < n;i++) {
		if (par[i] == -1) {
			dfs(i);
			break;
		}
	}

	for (int i = 0;i < n;i++) {
		list = false;
		printf("node %d: parent = %d, depth = %d, ", i, par[i], depth[i]);
		if (par[i] == -1) {
			printf("root, [");
			list = true;
		}
		else if (ch[i].empty()) {
			printf("leaf, []");
		}
		else {
			printf("internal node, [");
			list = true;
		}
		if (list) {
			if (ch[i].empty()) printf("]");
			for (int j = 0;j < ch[i].size();j++) {
				printf("%d", ch[i][j]);
				if (j + 1 == ch[i].size()) {
					printf("]");
				}
				else {
					printf(", ");
				}
			}
		}
		printf("\n");
	}

	return 0;
}