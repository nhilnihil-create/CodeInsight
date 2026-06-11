#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct tree {
	int node;
	int parent = -1;
	int depth = 0;
	vector<int> edge;
};

vector<struct tree> Tr(100001);

void ini_dep(int n) {
	for (int i = 0; i < Tr[n].edge.size(); i++) {
		int next = Tr[n].edge[i];
		Tr[next].depth = Tr[n].depth + 1;
		ini_dep(next);
	}
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int n; cin >> n;
//	vector<struct tree> Tr(n);
	for (int i = 0; i < n;i++) {
		int id, k, c; cin >> id >> k;
		Tr[id].node = id;
		for (int j = 0; j < k;j++) {
			cin >> c;
			Tr[c].parent = id;
			//Tr[c].depth = Tr[id].depth + 1;
			Tr[id].edge.push_back(c);
		}
	}

	int root;
	for (int i = 0; i < n; i++) {
		if (Tr[i].parent == -1) { root = i; }
	}

	ini_dep(root);

	for (int i = 0; i < n;i++) {
		cout << "node " << i << ": parent = " << Tr[i].parent << ", depth = " << Tr[i].depth
			<< ", ";
		if (Tr[i].parent == -1) { cout << "root, ["; }
		else if (Tr[i].edge.size() != 0) { cout << "internal node, ["; }
		else { cout << "leaf, ["; }
		for (int j = 0; j < Tr[i].edge.size(); j++) {
			if (j != Tr[i].edge.size() - 1) {
				cout << Tr[i].edge[j] << ", ";
			}
			else {
				cout << Tr[i].edge[j];
			}
		}
		cout << "]" << endl;
	}
}