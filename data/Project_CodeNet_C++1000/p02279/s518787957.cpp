#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class node{
public:
	int id;
	vector<int> children;
	int parent;
	int depth;
};

bool operator<=(node a, node b) {
	return a.id <= b.id;
}
bool operator<(node a, node b) {
	return a.id < b.id;
}

int main() {
	int  n,tmp,tmp2,index_root;
	cin >> n;
	node* nod = new node[n];
	bool* root = new bool[n];
	for (int i = 0;i < n;i++) {
		cin >> nod[i].id;
		cin >> tmp;
		for (int j = 0;j < tmp;j++) {
			cin >> tmp2;
			nod[i].children.push_back(tmp2);
		}
		root[i] = true;
	}
	sort(nod, nod + n);
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < nod[i].children.size();j++) {
			root[nod[i].children[j]] = false;
		}
	}
	for (int i = 0;i < n;i++) {
		if (root[i]) {
			index_root = i;
			break;
		}
	}
	nod[index_root].depth = 0;
	nod[index_root].parent = -1;
	queue<node*> q;
	q.push(&nod[index_root]);
	node* work_node;
	while (!q.empty()) {
		work_node = q.front();
		q.pop();
		for (int i = 0;i < work_node->children.size();i++) {
			nod[work_node->children[i]].parent = work_node->id;
			nod[work_node->children[i]].depth = work_node->depth + 1;
			q.push(nod + work_node->children[i]);
		}
	}
	for (int i = 0;i < n;i++) {
		cout << "node " << i << ": parent = " << nod[i].parent << ", depth = " << nod[i].depth << ", ";
		if (nod[i].depth == 0) {
			cout << "root, ";
		}
		else if (nod[i].children.size() == 0) {
			cout << "leaf, ";
		}
		else {
			cout << "internal node, ";
		}
		cout << "[";
		for (int j = 0;j < nod[i].children.size();j++) {
			cout << nod[i].children[j];
			if (j != nod[i].children.size() - 1) {
				cout << ", ";
			}
		}
		cout << "]" << endl;
	}


}


