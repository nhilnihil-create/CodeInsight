#include<iostream>
using namespace std;
#define NIL -1

int Depth[100005], n;

struct Node {
	int parent, left, right;
};

Node c[100005];

void print(int i) {
	int nod, j;
	cout << "node " << i << ": parent = " << c[i].parent << ", depth = " << Depth[i] << ", ";
	if (c[i].parent == NIL) cout << "root, [";
	else if (c[i].left == NIL) cout << "leaf, [";
	else cout << "internal node, [";
	for (j = 0, nod = c[i].left;nod != NIL;j++, nod = c[nod].right) {
		if (j > 0) cout << ", ";
		cout << nod;
	}
	cout << "]" << endl;
}

void calcdepth(int curnode, int dep) {
	Depth[curnode] = dep;
	if (c[curnode].right != NIL) calcdepth(c[curnode].right, dep);
	if (c[curnode].left != NIL) calcdepth(c[curnode].left, dep + 1);
}

int main() {
	int id, k, a, prenode, root;

	cin >> n;

	for (int i = 0;i <= n - 1;i++) c[i].parent = c[i].left = c[i].right = NIL;

	for (int i = 0;i <= n - 1;i++) {
		cin >> id >> k;
		for (int j = 0;j <= k - 1;j++) {
			cin >> a;
			if (j == 0) c[id].left = a;
			else c[prenode].right = a;
			prenode = a;
			c[a].parent = id;
		}
	}

	//root??????????????¢???
	for (int i = 0;i <= n - 1;i++) {
		if (c[i].parent == NIL) root = i;
	}

	calcdepth(root, 0);

	for (int i = 0;i <= n - 1;i++) print(i);

	return 0;
}