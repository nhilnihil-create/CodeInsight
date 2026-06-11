#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
using namespace std;

struct Node {
	string type;
	int depth;
	int parent = -1;
	vector<int> child;
};

int main() {
	int n;
	Node node[100000];
	queue<Node*> q;
	int depth = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int id, k;
		cin >> id >> k;
		for (int j = 0; j < k; j++) {
			int temp;
			cin >> temp;
			node[id].child.push_back(temp);
			node[temp].parent = id;
		}
	}

	for (int i = 0; i < n; i++) {
		if (node[i].parent == -1) {
			q.push(&node[i]);
			break;
		}
	}

	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {

			if (q.front()->parent == -1) {
				q.front()->type = "root";
			}
			else if (q.front()->child.empty()) {
				q.front()->type = "leaf";
			}
			else {
				q.front()->type = "internal node";
			}

			for (int j = 0; j < q.front()->child.size(); j++) {
				q.push(&node[q.front()->child[j]]);
			}
			q.front()->depth = depth;
			q.pop();
		}
		depth++;
	}

	for (int i = 0; i < n; i++) {
		cout << "node " << i << ": parent = " << node[i].parent << ", ";
		cout << "depth = " << node[i].depth << ", ";
		cout << node[i].type << ", ";
		cout << "[";
		for (int j = 0; j < node[i].child.size(); j++) {
			cout << node[i].child[j];
			if (j < node[i].child.size() - 1) {
				cout << ", ";
			}
		}
		cout << "]" << endl;
	}

	return 0;
}