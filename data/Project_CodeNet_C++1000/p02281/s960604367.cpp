#include <iostream>

using namespace std;

const int NIL = -1; 

typedef struct {
	int degree; //度 
	int parent; 
	int left;
	int right;
} Node;

Node *Tree; //树 

/*int *Depth; //深度 

int *Heigh; //高度 

void setDepth(int node,int dep) {
	Depth[node] = dep;
	if (Tree[node].left != NIL) {
		setDepth(Tree[node].left,dep+1);
	}
	if (Tree[node].right != NIL) {
		setDepth(Tree[node].right,dep+1);
	}
}

void setHeigh(int node) {	
	if (Tree[node].left == NIL && Tree[node].right == NIL) {
		Heigh[node] = 0;
		return;
	}
	if (Tree[node].left != NIL) {
	    setHeigh(Tree[node].left);
    }
    
    if (Tree[node].right != NIL) {
    	setHeigh(Tree[node].right);
    }
    
	int leftH = Tree[node].left == NIL ? 0 : Heigh[Tree[node].left];
	int rightH = Tree[node].right == NIL ? 0 : Heigh[Tree[node].right];
	Heigh[node] = max(leftH,rightH) + 1;
}

void printTree(int n) {
	for (int i=0;i<n;i++) {
		cout << "node " << i << ": parent = " << Tree[i].parent << ", sibling = ";
		if (Tree[i].parent == NIL) {
			cout << NIL;
		} else {
			int parent = Tree[i].parent;
			if (i == Tree[parent].left) {
				cout << Tree[parent].right;
			} else {
				cout << Tree[parent].left;
			}
		}
		cout << ", degree = " << Tree[i].degree << ", depth = " << Depth[i] << ", height = " << Heigh[i] << ", ";
		if (Tree[i].parent == NIL) {
			cout << "root";
		} else if (Tree[i].degree == 0) {
			cout << "leaf"; 
		} else if (Tree[i].degree > 0) {
			cout << "internal node";
		} 
		cout << endl;
	}
}*/

void Preorder(int node) {
	cout << " " << node;
	if (Tree[node].left != NIL) {
	  Preorder(Tree[node].left);
    }
    if (Tree[node].right != NIL) {
	  Preorder(Tree[node].right);
    }
}

void Inorder(int node) {
	if (Tree[node].left != NIL) {
	  Inorder(Tree[node].left);
    }
    cout << " " << node;
    if (Tree[node].right != NIL) {
	  Inorder(Tree[node].right);
    }
}

void Postorder(int node) {
	if (Tree[node].left != NIL) {
	  Postorder(Tree[node].left);
    }
    if (Tree[node].right != NIL) {
	  Postorder(Tree[node].right);
    }
    cout << " " << node;
}

int main() {
	int n;
	cin >> n;
	Tree = new Node[n];
	/*Depth = new int[n];
	Heigh = new int[n];*/
	 
	for (int i=0;i<n;i++) {
		Tree[i].parent = Tree[i].left = Tree[i].right = NIL;
	}
	
	for (int i=0;i<n;i++) {
		int p,l,r;
		cin >> p >> l >> r;
		Tree[p].left = l;
		Tree[p].right = r;
		Tree[p].degree = 0;
		if (l != NIL) {
			Tree[l].parent = p;
			Tree[p].degree++;
		}
		
		if (r != NIL) {
			Tree[r].parent = p;
			Tree[p].degree++;
		}
	}
	int root;
	for (int i=0;i<n;i++) {
		if (Tree[i].parent == NIL) {
			root = i;
			break;
		}
	}
	/*setDepth(root,0);
	setHeigh(root);*/
	cout << "Preorder" << endl;
	Preorder(root);
	cout << endl;
	cout << "Inorder" << endl;
	Inorder(root);
	cout << endl;
	cout << "Postorder" << endl;
	Postorder(root);
	cout << endl;
	
	delete[] Tree;
	
	/*delete[] Depth;
	delete[] Heigh;*/
	
	return 0;
	
}
