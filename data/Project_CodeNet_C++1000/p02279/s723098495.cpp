#include<iostream>
#include<vector>
#include<string>
using namespace std;

struct tree {
	vector<int> children;
	int depth;
	int parent;
	string type; // root, leef, internal node
};

tree trees[100000];

int calc_depth(int n) {
	for (vector<int>::iterator i = trees[n].children.begin(); i < trees[n].children.end(); i++) {
		trees[*i].depth = trees[n].depth + 1;
		calc_depth(*i);
	}
}

int main(void) {
	// ??\????????°
	int num;

	cin >> num;

	for (int i = 0; i < num; i++) {
		trees[i].parent = -1;
		trees[i].depth = 0;
	}

	// ?????¨?????????????????\??????
	for (int i = 0; i < num; i++) {
		int node, children;
		cin >> node >> children;
			for (int j = 0; j < children; j++) {
				int child;
				cin >> child;
				trees[node].children.push_back(child);
				trees[child].parent = node;
		}
	}

	// depth????±???????
	for (int i = 0; i < num; i++) {
		if (trees[i].parent == -1) {
			calc_depth(i);
		}
	}

	for (int i = 0; i < num; i++) {
		if (trees[i].parent == -1) {
			trees[i].type = "root";
		} else if (trees[i].children.size() == 0) {
			trees[i].type = "leaf";
		} else {
			trees[i].type = "internal node";
		}
	}

	for (int i = 0; i < num; i++) {
		cout << "node " << i << ": parent = " << trees[i].parent;
		cout << ", depth = " << trees[i].depth << ", " << trees[i].type;
		cout << ", [";
		for (int j = 0; j < trees[i].children.size(); j++) {
			cout << trees[i].children[j];
			if (j != trees[i].children.size() - 1) {
				cout << ", ";
			}
		}
		cout << "]" << endl;
	}
	return 0;
}