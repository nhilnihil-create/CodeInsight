#include<iostream>
#include<list>
#include<vector>
#include <cstdio>
#include<string>
static const int	RootParentID = -1;
static const int	NIL = -2;
class node {
private:
	int Parent;
	int LeftChild;
	int RightBro;
public:
	node() {
		Parent = RootParentID;
		LeftChild = RightBro = NIL;
	}

	int CheckDepth(const std::vector<node> & nodes) {
		int CheckNodeParent = Parent;
		int cnt = 0;
		while (CheckNodeParent != RootParentID) {
			++cnt;
			CheckNodeParent = nodes[CheckNodeParent].Parent;
		}
		return cnt;
	}
	void AddParent(int id) {
		Parent = id;
		return;
	}
	void AddRightBro(int id) {
		RightBro = id;
		return;
	}
	void AddLeftChild(int id) {
		LeftChild = id;
		return;
	}
	int GetParent() {
		return Parent;
	}
	int GetLeftChild() {
		return LeftChild;
	}
	int GetRightBro() {
		return RightBro;
	}
};
int main(void) {
	//	std::ios_base::sync_with_stdio(false);
	int n;
	std::cin >> n;
	int id, k;
	int child;
	//	node * nodes = new node[ n];
	std::vector<node> nodes(n);
	for (int i = 0; i < n; i++) {
		std::cin >> id >> k;
		std::vector<int> v(k + 1);
		for (int j = 0; j < k; ++j) {
			std::cin >> child;
			v[j] = child;
		}
		v[k] = NIL;
		for (int j = 0; j < k; ++j) {
			nodes[v[j]].AddParent(id);
			nodes[v[j]].AddRightBro(v[j + 1]);
		}
		nodes[id].AddLeftChild(v[0]);
	}
	for (int i = 0; i < n; ++i) {
		printf("node %d: parent = %d, depth = %d, %s, [", i, nodes[i].GetParent(), nodes[i].CheckDepth(nodes),(nodes[i].GetParent() == RootParentID ? "root" : (nodes[i].GetLeftChild() == NIL ? "leaf" : "internal node")) );
		if (nodes[i].GetLeftChild() == NIL) printf("]\n");
		for (int k = nodes[i].GetLeftChild(); k != NIL; k = nodes[k].GetRightBro()) {
			printf("%d%s", k, (nodes[k].GetRightBro() == NIL ? "]\n" : ", "));
		}
	}
	//system("pause");
	return 0;
}