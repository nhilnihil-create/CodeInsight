#include <iostream>
#include <vector>
using namespace std;
struct Node
{
	Node(int k) : depth(0) { vChildId.resize(k, -1); }
	int depth;
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
	vector<int> vParentId(nu, -1);
	vector<Node*> vNode(nu, (Node*)0);
	while (nu--){
		cin >> id >> k;
		vNode[id] = new Node(k);
		for (int j = 0; j < k; ++j){
			cin >> c;
			vNode[id]->vChildId[j] = c;
			vParentId[c] = id;
		}
	}
	vector<Node*> vRoot;
	for (int i = 0; i < vNode.size(); ++i){
		if (vParentId[i] == -1)
			vRoot.push_back(vNode[i]);
	}
	for (int i = 0; i < vRoot.size(); ++i)
		SetNodeDepthRecursive(vRoot[i], vNode);

	Node* n;
	int pid;
	for (int i = 0; i < vNode.size(); ++i){
		n = vNode[i];
		pid = vParentId[i];
		cout << "node " << i << ": parent = " << pid << ", depth = " << n->depth << ", ";
		if (pid == -1){
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