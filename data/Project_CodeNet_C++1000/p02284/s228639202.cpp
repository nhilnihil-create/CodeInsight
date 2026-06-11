#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;

//ノードを表す構造体を定義する
struct Node {
	int key;
	Node* left, * right, * parent; //左の子、右の子、親を指すポインタ
};

typedef struct Node* node;

node root, NIL;
//preorder tree walk
void preorder(node u) {
	if (u == NIL) {
		return;
	}
	cout << " " << u->key;
	preorder(u->left);
	preorder(u->right);

}

//inorder walk
void inorder(node u) {
	if (u == NIL) {
		return;
	}
	inorder(u->left);
	cout << " " << u->key;
	inorder(u->right);
}

void insert(int k) {
	node y = NIL;		//xの親
	node x = root;
	node z = NIL;

	z = (Node*)malloc(sizeof(Node));
	z->key = k;
	z->left = NIL;
	z->right = NIL;

	while (x != NIL) {
		y = x;		//親を設定
		if (z->key < x->key) {
			x = x->left;		//左の子へ移動
		}
		else {
			x = x->right;		//右の子へ移動

		}
	}
	z->parent = y;
	if (y == NIL) {	//Tが空の場合
		root = z;
	}
	else {
		if (z->key < y->key) {
			y->left = z;		//zをyの左の子にする
		}
		else {
			y->right = z;		//zをyの右の子にする
		}
	}

}
/*
node find(node x, int k) {
	while (x != NIL and k != x->key) {

		if (k < x->key) {
			x = x->left;	//左の子へ移動
		}
		else {
			x = x->right;	//右の子へ移動
		}
	}
	return x;
}
*/

bool find(node x, int k) {
	if (x->key == k) {
		return true;
	}
	else if (k < x->key) {
		if (x->left == NIL) {
			return false;
		}
		find(x->left, k);

	}
	else if(k > x->key) {
		if (x->right == NIL) {
			return false;
		}
		find(x->right, k);
	}
}
int main() {
	int n, i, x;
	string com;
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		cin >> com;
		if (com == "insert") {
			scanf("%d", &x);
			insert(x);
		}
		else if (com == "print") {
			inorder(root);
			printf("\n");
			preorder(root);
			printf("\n");
		}
		else if (com == "find") {
			scanf("%d", &x);
			if (find(root, x) )printf("yes\n");
			else printf("no\n");
		}
	}

	return 0;
}
