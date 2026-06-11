#include <iostream>
#include <vector>
using namespace std;

struct rootedTree {
	struct node {
		int bro, chi, par;
	};

	vector<int> dep;
	vector<node> tree;

	rootedTree(int n) :
		dep(n),
		tree(n)
	{
		for (node& i : tree) i.bro = i.chi = i.par = -1;
	}

	int getBrother(int a) {
		return tree[a].bro;
	}

	int getChild(int a) {
		return tree[a].chi;
	}

	int getDepth(int a) {
		return dep[a];
	}

	int getParent(int a) {
		return tree[a].par;
	}

	vector<int> getChildren(int a) {
		int b = tree[a].chi;
		vector<int> res;
		while (b != -1) {
			res.push_back(b);
			b = tree[b].bro;
		}
		return res;
	}

	void setBrother(int a, int newBro) {
		tree[a].bro = newBro;
	}

	void setChild(int a, int newChi) {
		tree[a].chi = newChi;
	}

	void setParent(int a, int newPar) {
		tree[a].par = newPar;
	}

	void updateDepth(int a, int b) {
		dep[a] = b;
		if (tree[a].bro != -1) updateDepth(tree[a].bro, b);
		if (tree[a].chi != -1) updateDepth(tree[a].chi, b + 1);
	}
};

int main() {
	int n, id, k, c, tmp1;
	cin >> n;
	rootedTree rt(n);
	for (int i = 0; i < n; ++i) {
		cin >> id >> k;
		for (int j = 0; j < k; ++j) {
			cin >> c;
			if (j) rt.setBrother(tmp1, c);
			else rt.setChild(id, c);
			tmp1 = c;
			rt.setParent(c, id);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (rt.getParent(i) == -1) {
			tmp1 = i;
			break;
		}
	}
	rt.updateDepth(tmp1, 0);
	for (int i = 0; i < n; ++i) {
		vector<int> tmp2 = rt.getChildren(i);
		cout << "node " << i << ": parent = " << rt.getParent(i) << ", depth = " << rt.getDepth(i) << ", ";
		if (rt.getParent(i) == -1) cout << "root, [";
		else if (rt.getChild(i) == -1) cout << "leaf, [";
		else cout << "internal node, [";
		if (!tmp2.empty()) cout << tmp2[0];
		for (int j = 1; j < tmp2.size(); ++j) cout << ", " << tmp2[j];
		cout << "]" << endl;
	}
}
