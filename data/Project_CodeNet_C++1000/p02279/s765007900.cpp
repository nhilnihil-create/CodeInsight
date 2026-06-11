#include<iostream>
#define INDEX 100000
#define NULLL -1
using namespace std;

struct Node {
	int parent;
	int left;
	int right;
};

Node node[INDEX];
int depth[INDEX];

void setDepth(int u, int p);
void printChildren(int u);

int main() {
	int i, j, n, d, id, dim, tmp, cleft;
	
	cin >> n;
	
	for (i = 0; i < n; i++) {
		node[i].parent = NULLL;
		node[i].left = NULLL;
		node[i].right = NULLL;
	}
	
	for (i = 0; i < n; i++) {
		cin >> id >> dim;
		for (j = 0; j < dim; j++) {
			cin >> tmp;
			if (j == 0) node[id].left = tmp;
			else node[cleft].right = tmp;
			node[tmp].parent = id;
			cleft = tmp;
		}
	}

	i = 0;
	while(1) {
		if (node[i].parent == NULLL)break;
		i++;
	}
	setDepth(i, 0);

	for (i = 0; i < n; i++) {
		cout << "node " << i << ": parent = " << node[i].parent << ", depth = " << depth[i] << ", ";
		if (node[i].parent == NULLL)cout << "root";
		else if (node[i].left == NULLL)cout << "leaf";
		else cout << "internal node";
		cout << ", ";
		printChildren(i);
	}

	return 0;
}

void setDepth(int u, int p) {
	depth[u] = p;
	if (node[u].right != NULLL)setDepth(node[u].right, p);
	if (node[u].left != NULLL)setDepth(node[u].left, p + 1);
}

void printChildren(int u) {
	int i = 0, cleft;
	if (node[u].left == NULLL) {
		cout << "[]\n";
		return;
	}
	cout << "[" << node[u].left;
	cleft = node[u].left;
	while (node[cleft].right != NULLL) {
		cout << ", " << node[cleft].right;
		cleft = node[cleft].right;
	}
	cout << "]\n";
}