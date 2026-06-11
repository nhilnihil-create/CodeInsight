#include<iostream>
#include<algorithm>
#define MAX 26
#define NIL -1
using namespace std;

struct Node {
	int parent, left, right;
};

void printPreOrder(Node node[], int parent);
void printInOrder(Node node[], int left);
void printPostOrder(Node node[], int left);

int main() {
	Node node[MAX];
	int i, j, n, id, root, left;
	cin >> n;
	for (i = 0; i < n; i++) {
		node[i].parent = NIL;
		node[i].left = NIL;
		node[i].right = NIL;
	}

	for (i = 0; i < n; i++) {
		cin >> id;
		cin >> node[id].left >> node[id].right;
		node[node[id].left].parent = id;
		node[node[id].right].parent = id;
	}

	root = 0;
	while (node[root].parent != NIL) {
		root = node[root].parent;
	}

	cout << "Preorder\n";
	printPreOrder(node, root);
	cout << "\nInorder\n";
	printInOrder(node, root);
	cout << "\nPostorder\n";
	printPostOrder(node, root);
	cout << endl;

	return 0;
}

void printPreOrder(Node node[], int parent) {
	cout << " " << parent;
	if (node[parent].left != NIL)printPreOrder(node, node[parent].left);
	if (node[parent].right != NIL)printPreOrder(node, node[parent].right);
}

void printInOrder(Node node[], int parent) {
	if (node[parent].left != NIL)printInOrder(node, node[parent].left);
	cout << " " << parent;
	if (node[parent].right != NIL)printInOrder(node, node[parent].right);
}

void printPostOrder(Node node[], int parent) {
	if (node[parent].left != NIL)printPostOrder(node, node[parent].left);
	if (node[parent].right != NIL)printPostOrder(node, node[parent].right);
	cout << " " << parent;
}