#include <iostream>

using namespace std;

const int NIL = -1;

typedef struct {
	int parent;
	int left;
	int right;
} Node;

Node *Tree; //树

int *Depth; //深度 

//计算深度 
void setDepth(int node,int dep) {
	Depth[node] = dep;
	if (Tree[node].left != NIL) {
		setDepth(Tree[node].left,dep+1);
	} 
	
	if (Tree[node].right != NIL) {
		setDepth(Tree[node].right,dep);
	}
}

void printTree(int node) {
	cout << "node " << node << ": parent = " << Tree[node].parent << ", depth = " << Depth[node] << ", ";
	if (Tree[node].parent == NIL) {
		cout << "root";
	} else if (Tree[node].left != NIL) {
		cout << "internal node";
	} else {
		cout << "leaf";
	}
	cout << ", [";
	bool flag = 1;
	for (int nod = Tree[node].left;nod != NIL;nod = Tree[nod].right) {
		if (!flag) {
			cout << ", ";
		}
		cout << nod;
		flag = 0;
	}
	cout << "]" << endl;
}

int main() {
	int n;
	cin >> n;
	Tree = new Node[n];
	Depth = new int[n];
	
	for (int i=0;i<n;i++) {
		Tree[i].parent = Tree[i].left = Tree[i].right = NIL;
	}
	for (int i=0;i<n;i++) {
		int p,degree;;
		cin >> p >> degree;
		int index;
		for (int i=0;i<degree;i++) {
			int x;
			cin >> x;
			if (i == 0) {
				Tree[p].left = x;
				index = x;
			} else {
				Tree[index].right = x;
				index = x;
			}
			Tree[x].parent = p;
		}
	}
	
	int root;
	for (int i=0;i<n;i++) {
		if (Tree[i].parent == NIL) {
			root = i;
		}
	}
	setDepth(root,0);
	for (int i=0;i<n;i++) {
		printTree(i);
	}
	delete[] Tree;
	delete[] Depth;
	return 0;
}

