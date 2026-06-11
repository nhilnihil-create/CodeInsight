#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

struct Node {
	int key;
	Node* p;
	Node* l;
	Node* r;
};

Node* root;
Node* NIL;
//	insert(T, z)
//	    y = NIL // x ??????
//	    x = 'T ??????'
//	    while x ??? NIL
//	        y = x // ???????¨????
//	        if z.key < x.key
//	            x = x.left // ?????????????§????
//	        else
//	            x = x.right // ?????????????§????
//	    z.p = y
//
//	    if y == NIL // T ???????????´???
//	        'T ??????' = z
//	    else if z.key < y.key
//	        y.left = z // z ??? y ?????????????????????
//	    else
//	        y.right = z // z ??? y ?????????????????????

void insert(int z) {

	Node* y = NIL;
	Node* x = root;

	Node* zn = (Node *) malloc(sizeof(Node));
	zn->key = z;
	zn->l = NIL;
	zn->r = NIL;

	while (x != NIL) {
		y = x;
		if (zn->key < x->key)
			x = x->l;
		else
			x = x->r;
	}

	if (y == NIL)
		root = zn;
	else if (zn->key < y->key)
		y->l = zn;
	else
		y->r = zn;

}

void printInOrder(Node* n) {
	if (n == NIL)
		return;

	printInOrder(n->l);
	cout << " " << n->key;
	printInOrder(n->r);
}

void printPreOrder(Node* n) {
	if (n == NIL)
		return;
	cout << " " << n->key;
	printPreOrder(n->l);
	printPreOrder(n->r);
}

int main() {

	int n;
	scanf("%d", &n);

	string s;
	int k;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (s == "insert") {
			scanf("%d", &k);
			insert(k);
		} else {
			printInOrder(root);
			cout << endl;
			printPreOrder (root);
			cout << endl;
		}
	}

	return 0;
}