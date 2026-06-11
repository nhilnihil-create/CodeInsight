#include <iostream>

using namespace std;
#define MAXN 100005
#define NIL -1

struct Node{
	int p, l, r;
};

Node T[MAXN];
int n, D[MAXN];

void print(int u){
	int i, c;
	cout << "node " << u << ": ";
	cout << "parent = " << T[u].p << ", ";
	cout << "depth = " << D[u] << ", ";
	
	if (T[u].p == NIL) {
		cout << "root, ";
	}else if (T[u].l == NIL) {
		cout << "leaf, ";
	}else {
		cout << "internal node, ";
	}
	
	cout << "[";
	
	for (i = 0, c = T[u].l; c != NIL; i++, c = T[c].r) {
		if (i) {
			cout << ", ";
		}
		cout << c;
	}
	cout << "]" << endl;
}

void setDepth(int u, int p){
	D[u] = p;
	if (T[u].r != NIL) {
		setDepth(T[u].r, p);
	}
	if (T[u].l != NIL) {
		setDepth(T[u].l, p+1);
	}
}

int main(int argc, char *argv[]) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		T[i].p = T[i].l = T[i].r = NIL;
	}

	for (int i = 0; i < n; i++) {
		int v, m, l;
		cin >> v >> m;
		for (int j = 0; j < m; j++) {
			int child;
			cin >> child;
			if (j == 0) {
				T[v].l = child;
			}else {
				T[l].r = child;
			}
			l = child;
			T[child].p = v;
		}
	}
	int root;
	for (int i = 0; i < n; i++) {
		if (T[i].p == NIL) {
			root = i;
		}
	}
	setDepth(root, 0);
	for (int i = 0; i < n; i++) {
		print(i);
	}
	return 0;
}
