// ALDS1_7_C
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int parent;
	int children[2];
};

void pre_walk(vector<Node> Tree, int p) {
	cout << " " << p;
	
	for (int i = 0; i < 2; i++) 
		if (Tree[p].children[i] != -1)
			pre_walk(Tree, Tree[p].children[i]);
}

void in_walk(vector<Node> Tree, int p) {
	if (Tree[p].children[0] != -1)
		in_walk(Tree, Tree[p].children[0]);
	
	cout << " " << p;

	if (Tree[p].children[1] != -1)
		in_walk(Tree, Tree[p].children[1]);
}

void post_walk(vector<Node> Tree, int p) {
	for (int i = 0; i < 2; i++)
		if (Tree[p].children[i] != -1)
			post_walk(Tree, Tree[p].children[i]);

	cout << " " << p;
}

int main() {

	int n, id, left, right, root;
	cin >> n;

	vector<Node> Tree;

	for (int i = 0; i < n; i++) {
		Node node;
		node.parent = -1;
		Tree.push_back(node);
	}

	for (int i = 0; i < n; i++) {
		cin >> id >> left >> right;

		Tree[id].children[0] = left;
		Tree[id].children[1] = right;
		for (int j = 0; j < 2; j++)
			if (Tree[id].children[j] != -1) 
				Tree[Tree[id].children[j]].parent = id;
	}

	for (int i = 0; i < n; i++) {
		if (Tree[i].parent == -1)
			root = i;
	}

	cout << "Preorder" << endl;
	pre_walk(Tree, root);
	cout << endl;

	cout << "Inorder" << endl;
	in_walk(Tree, root);
	cout << endl;

	cout << "Postorder" << endl;
	post_walk(Tree, root);
	cout << endl;

	return 0;
}

