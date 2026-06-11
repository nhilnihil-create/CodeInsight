#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
	int parent = -1;
	vector<int> child;
};

vector<Node> node;

int get_depth(int id, int depth) {
	if (node[id].parent == -1) {
		return depth;
	}
	else {
		get_depth(node[id].parent, depth + 1);
	}
}

string get_type(int id) {
	if (node[id].parent == -1) {
		return "root";
	}
	else if (node[id].child.size() == 0) {
		return "leaf";
	}
	else {
		return "internal node";
	}
}

int main() {
	int n, id, k, child;

	cin >> n;
	node.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> id >> k;
		for (int j = 0; j < k; j++) {
			cin >> child;
			node[id].child.push_back(child);
			node[child].parent = id;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << "node " << i << ": ";
		cout << "parent = " << node[i].parent << ", ";
		cout << "depth = " << get_depth(i, 0) << ", ";
		cout << get_type(i) << ", [";
		for (int j = 0; j < node[i].child.size(); j++) {
			cout << node[i].child[j];
			if (j < node[i].child.size() - 1) {
				cout << ", ";
			}
		}
		cout << "]\n";
	}

	return 0;
}