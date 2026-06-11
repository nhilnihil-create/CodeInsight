#include<iostream>
#include<vector>
static const int NIL = -1;
static const int NumberChild = 2;
class Tree {
private:
	int id;
	int parent;
	int child[NumberChild];

public:
	Tree() {
		id = child[0] = child[1] = parent = NIL;
	}
	void AddParent(int ID) {
		parent = ID;
		return;
	}
	void AddID(int ID) {
		id = ID;
		return;
	}
	void AddChild(std::vector<int>&Child) {
		for (unsigned int i = 0; i < Child.size(); ++i) {
			child[i] = Child[i];

		}

		return;
	}
	int GetRoot(std::vector<Tree> nodes, int ID) {
		int RootID = ID;
		if (RootID != NIL&&nodes[RootID].parent != NIL) {
			RootID=GetRoot(nodes, nodes[RootID].parent);
		}
		return RootID;
	}
	void PreorderTreeWalk(std::vector<Tree> nodes, int ID) {
		if (ID != NIL) {
			std::cout << " " << ID;
			PreorderTreeWalk(nodes, nodes[ID].child[0]);
			PreorderTreeWalk(nodes, nodes[ID].child[1]);
		}

		return;
	}
	void InorderTreeWalk(std::vector<Tree> nodes, int ID) {
		if (ID != NIL) {
			InorderTreeWalk(nodes, nodes[ID].child[0]);
			std::cout << " " << ID;
			InorderTreeWalk(nodes, nodes[ID].child[1]);
		}

		return;
	}
	void PostorderTreeWalk(std::vector<Tree> nodes, int ID) {
		if (ID != NIL) {

			PostorderTreeWalk(nodes, nodes[ID].child[0]);
			PostorderTreeWalk(nodes, nodes[ID].child[1]);
			std::cout << " " << ID;
		}

		return;
	}
};
int main(void) {
	int n;
	std::cin >> n;
	std::vector<Tree>nodes(n);
	int ID;
	std::vector<int> child(NumberChild);
	for (int i = 0; i < n; ++i) {
		std::cin >> ID;
		nodes[ID].AddID(ID);
		for (int i = 0; i < 2; ++i) {
			std::cin >> child[i];
			if (child[i] != NIL) {
				nodes[child[i]].AddParent(ID);
			}
		}
		nodes[ID].AddChild(child);

	}
	int ROOTID = nodes[0].GetRoot(nodes, 0);
	std::cout << "Preorder\n";
	nodes[0].PreorderTreeWalk(nodes, ROOTID);
	std::cout << "\nInorder\n";
	nodes[0].InorderTreeWalk(nodes, ROOTID);
	std::cout << "\nPostorder\n";
	nodes[0].PostorderTreeWalk(nodes, ROOTID);
	std::cout << "\n";
	//system("pause");
	return 0;
}