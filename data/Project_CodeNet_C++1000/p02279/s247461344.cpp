#include <iostream>
#include <vector>
using namespace std;
struct Node
{
	Node(int k) : depth(0), parentId(-1) { vChildId.resize(k, -1); }
	int depth;
	int parentId;
	vector<int> vChildId;
};

void SetNodeDepthRecursive(Node* n, vector<Node*>& vNode)
{
	int s = n->vChildId.size();
	if (0 == s) return;
	for (int i = 0; i < s; ++i){
		Node* cn = vNode[n->vChildId[i]];
		cn->depth = n->depth + 1;
		SetNodeDepthRecursive(cn, vNode);
	}
}

int main()
{
	int nu, id, k, c;
	cin >> nu;
	vector<Node*> vNode(nu, (Node*)0);
	while (nu--){
		cin >> id >> k;
		vNode[id] = new Node(k);
		for (int j = 0; j < k; ++j){
			cin >> c;
			vNode[id]->vChildId[j] = c;
		}
	}
	for (int i = 0; i < vNode.size(); ++i){
		Node* n = vNode[i];
		for (int j = 0; j < n->vChildId.size(); ++j){
			Node* cn = vNode[n->vChildId[j]];
			cn->parentId = i;
		}
	}
	vector<Node*> vRoot;
	for (int i = 0; i < vNode.size(); ++i){
		if (vNode[i]->parentId == -1)
			vRoot.push_back(vNode[i]);
	}
	for (int i = 0; i < vRoot.size(); ++i)
		SetNodeDepthRecursive(vRoot[i], vNode);

	Node* n;
	for (int i = 0; i < vNode.size(); ++i){
		n = vNode[i];
		cout << "node " << i << ": parent = " << n->parentId << ", depth = " << n->depth << ", ";
		if (n->parentId == -1){
			cout << "root, [";
			if (n->vChildId.size() == 0)
				cout << "]\n";
		}
		else if (n->vChildId.size() == 0) cout << "leaf, []\n";
		else cout << "internal node, [";
		if (n->vChildId.size() != 0){
			int cs = n->vChildId.size();
			for (int j = 0; j < cs; ++j){
				cout << n->vChildId[j];
				if (j < cs - 1)
					cout << ", ";
			}
			cout << "]\n";
		}
	}

	return 0;
}