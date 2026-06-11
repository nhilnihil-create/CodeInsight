#include <bits/stdc++.h>
using namespace std;

static const int NIL = -1;

struct Node {
	int parent;
	int left;
	int right;
	Node(int parent = NIL, int left = NIL, int right = NIL): parent(parent), left(left), right(right) {}
};

vector<Node> T;
vector<int> D;

void setDepth(int u, int depth)
{
	D[u] = depth;
	if (T[u].right != NIL) setDepth(T[u].right, depth);
	if (T[u].left != NIL) setDepth(T[u].left, depth + 1);
}

void print(int u)
{
	stringstream res;
	string type;
	if (T[u].parent == NIL) type = "root";
	else if (T[u].left == NIL) type = "leaf";
	else type = "internal node";
	
	res << "node " << u << ": ";
	res << "parent = " << T[u].parent << ", ";
	res << "depth = " << D[u] << ", ";
	res << type << ", [";
	
	bool f = false;
	for (int v = T[u].left; v != NIL; v = T[v].right){
		if (f) res << ", ";
		res << v;
		f = true;
	}
	res << "]";
	
	cout << res.str() << endl;
}

int main()
{
	int n;
	scanf("%d", &n);
	T.resize(n);
	D.resize(n);
	
	for (int i = 0; i < n; i++){
		int id, k;
		scanf("%d %d", &id, &k);
		
		int l = NIL;
		for (int j = 0; j < k; j++){
			int c;
			scanf("%d", &c);
			if (l == NIL) T[id].left = c;
			else T[l].right = c;
			l = c;
			T[c].parent = id;
		}
	}
	
	int root;
	for (int i = 0; i < n; i++){
		if (T[i].parent == NIL){
			root = i;
		}
	}
	
	setDepth(root, 0);
	
	for (int i = 0; i < n; i++){
		print(i);
	}
	
	return 0;
}