#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int parent, depth;
	string type;
	vector<int> list;

	Node() {
		parent = -1;
		depth = 0;
		type = "";
		list.clear();
	}
};

Node TreeInfo[100000];

void solve(int n) {
	int len, parent, startId, curId;
	string type;
	queue<int> nodeList;

	for (int id = 0; id < n; ++id) {
		len = TreeInfo[id].list.size();
		parent = TreeInfo[id].parent;
		if (parent == -1) {
			TreeInfo[id].type = "root";
			nodeList.push(id);
		}
		else if (len == 0) {
			TreeInfo[id].type = "leaf";
		}
		else {
			TreeInfo[id].type = "internal node";
		}
	}

	while(!nodeList.empty()) {
		startId = nodeList.front();
		nodeList.pop();

		len = TreeInfo[startId].list.size();
		for (int j = 0; j < len; ++j) {
			curId = TreeInfo[startId].list[j];
			TreeInfo[curId].depth += TreeInfo[startId].depth + 1;
			nodeList.push(curId);
		}
	}
}

void show(int n) {
	int len;

	for (int id = 0; id < n; ++id) {
		cout << "node " << id << ": ";
		cout << "parent = " << TreeInfo[id].parent << ", ";
		cout << "depth = " << TreeInfo[id].depth << ", ";
		cout << TreeInfo[id].type << ", [";
		len = TreeInfo[id].list.size();
		for (int j = 0; j < len; ++j) {
			cout << TreeInfo[id].list[j];
			cout << (j == len - 1 ? "" : ", ");
		}
		cout << "]" << endl;
	}
}

int main() {
	int n, id, k, c;

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> id >> k;
		for (int j = 0; j < k; ++j) {
			cin >> c;
			TreeInfo[id].list.push_back(c);
			TreeInfo[c].parent = id;
		}
	}
	solve(n);
	show(n);

	return 0;
}
