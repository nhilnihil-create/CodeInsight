#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

struct Node {
	long long key;
	Node* left;
	Node* right;
};

void inseart(Node** root, Node* data) {
	if (*root == NULL) {
		*root = data;
		return;
	}
	Node* prev = NULL;
	Node* node = *root;
	while (node != NULL) {
		prev = node;
		if (node->key > data->key) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}
	if (prev->key > data->key) {
		prev->left = data;
	}
	else {
		prev->right = data;
	}
}

void visit(Node* root, vector<int>& pre,vector<int>& ino) {
	pre.push_back(root->key);
	if (root->left != NULL) {
		visit(root->left, pre, ino);
	}
	ino.push_back(root->key);
	if (root->right != NULL) {
		visit(root->right, pre, ino);
	}
}

void print(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << " " << v[i];
	}
}


int main() {
	int n;
	int cnt = 0;
	Node node[500000];
	Node* root = NULL;

	cin >> n;
	for (int i = 0; i < n; i++) {
		string buf;
		vector<int> pre;
		vector<int> ino;
		int k;
		cin >> buf;
		if (buf == "insert") {
			cin >> k;
			node[cnt].key = k;
			node[cnt].left = NULL;
			node[cnt].right = NULL;
			inseart(&root, &node[cnt]);
			cnt++;
		}
		else {
			visit(root, pre, ino);
			print(ino);
			cout << endl;
			print(pre);
			cout << endl;
		}
	}
	return 0;
}