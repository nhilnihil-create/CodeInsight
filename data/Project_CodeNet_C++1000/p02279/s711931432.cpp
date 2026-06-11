#include <iostream>

#define MAX (1000000)
#define NIL (-1) // 番兵用node id

using namespace std;

struct Node {
	int parent, left, right;
};

struct Node T[MAX];
int n, D[MAX];

void print(int u) {
	int i,c;
	cout << "node " << u << ": ";
	cout << "parent = " << T[u].parent << ", ";
	cout << "depth = " << D[u] << ", ";

	if (T[u].parent == NIL) cout << "root, ";
	else if (T[u].left == NIL) cout << "leaf, ";
	else cout << "internal node, ";

	cout << "[";
	for (int i=0, c = T[u].left; c != NIL; ++i, c = T[c].right) {
		if (i) cout << ", ";
		cout << c;
	}
	cout << "]" << endl;
}

/// 深さの決定
int rec(int u, int p) {
	D[u] = p;
	if (T[u].right != NIL) rec(T[u].right, p); // 右の兄弟に同じ深さを設定
	if (T[u].left  != NIL) rec(T[u].left, p+1);// 最も左の子に自分の深さ+1を設定
}

int main() {
	int n;
	cin >> n;
	for (int i=0; i<n; ++i) {
		T[i].parent = T[i].left = T[i].right = NIL; 
	}
	/// 順番に処理
	for (int i=0; i<n; ++i) {
		// id vとchildの個数kを読み込み
		int v,k; 
		cin >> v >> k; 
		for (int j=0;j<k; ++j) {
			// childがあるときにchild idを読み込み
			int child_id;
			cin >> child_id;
			int l;
			// このnode vのmost left child に対して child_idを設定
			if (j == 0) T[v].left = child_id;
			// ひとつ前のchild idの1つ右の兄弟として, このchild_idを設定
			else T[l].right = child_id;
			// node vのchild idを取っておく
			l = child_id;
			// node vのchild のparentはnode vである
			T[child_id].parent = v;
		}
	}
	/// root nodeの決定 
	int root_node = 0;
	for (int i=0; i<n; ++i) {
		if (T[i].parent == NIL) root_node = i; 
	}
	/// root nodeからのdepthの決定
	rec(root_node, 0); // root_nodeのdepth = 0
	// print
	for (int i=0;i<n;++i) print(i);
	return 0;
}

