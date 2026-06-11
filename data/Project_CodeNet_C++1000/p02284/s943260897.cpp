#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>

using namespace std;

const double PI = 3.14159265358979;

struct Node {
	int key;
	Node* left, * right;
};

void preorder(Node* const root) {

	if (root) {
		printf(" %d", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node* const root) {

	if (root) {
		inorder(root->left);
		printf(" %d", root->key);
		inorder(root->right);
	}
}


void insert_key(Node *root, int key) {

	Node* comer = new Node;
	comer->key = key;
	comer->left = 0;
	comer->right = 0;

	Node* temp = root;
	Node* par = 0;
	while (temp) {
		par = temp;
		if (key < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if (key < par->key) par->left = comer;
	else par->right = comer;

}

bool find_key(Node* const root, int key) {
	
	Node* temp = root;
	while (temp) {
		if (temp->key == key) return true;

		if (key < temp->key)
			temp = temp->left;
		else if (key > temp->key)
			temp = temp->right;
		else
			return true;
	}
	return false;
}

void display_tree(Node* const root) {

	inorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
}

int main() {

	int n;  cin >> n;
	Node* root = 0;

	string cmd;
	int key;
	for (int i = 0; i < n; i++)	{
		cin >> cmd;
		if (cmd[0] == 'i') {
			cin >> key;
			if (!root) {
				root = new Node;
				root->key = key;
				root->left = root->right = 0;
			} else
				insert_key(root, key);
		} 
		else if (cmd[0] == 'p') {
			display_tree(root);
		}
		else if (cmd[0] == 'f') {
			cin >> key;
			bool res = find_key(root, key);
			if (res) cout << "yes\n";
			else cout << "no\n";
		}
	}

	return 0;
}

