#include <bits/stdc++.h>
using namespace std;
#define r(i,n) for(auto i=0;i<n;i++)

struct Node{
	int id;
	int depth;
	Node *parent;
	vector<Node*> childs;

    bool operator<( const Node& param ) const {
        return id < param.id;
    }
};
Node *nil;
list<int> ids;
map<int, list<int>> getChilds;
vector<Node> vectored;

void flat(Node* node){
	vectored.push_back(*node);
	for(Node* tmp : node->childs){
		flat(tmp);
	}
}

void conChilds(Node *node){
	for(int childId : getChilds[node->id]){
		Node *child = new Node();
		child->id = childId;
		child->depth = node->depth + 1;
		child->parent = node;
		(node->childs).push_back(child);
		conChilds(child);
	}
}

int main(){
	int n, id, k, t, maxId = 100000;
	cin >> n;

	r(i, n){
		cin >> id >> k;
		ids.push_back(id);
		list<int> childs;
		maxId = max(maxId, id);
		r(j, k){
			cin >> t;
			childs.push_back(t);
		}
		getChilds[id] = childs;
	}

	//search root
	bool isRoot[maxId+1]{};
	for(int id : ids){
		isRoot[id] = true;
	}
	for(int id : ids){
		for(int childId : getChilds[id]){
			isRoot[childId] = false;
		}
	}

	int rootId = -1;
	r(i, maxId+1){
		if(isRoot[i]){
			rootId = i;
			break;
		}
	}

	if(rootId == -1)
		printf("root couldn't be found");

	Node *root = new Node();
	root->id = rootId;
	root->depth = 0;
	root->parent = nil;

	conChilds(root);

	flat(root);
	sort(vectored.begin(), vectored.end());

	for(Node node : vectored){
		cout << "node " << node.id << ": ";
		cout << "parent = " << (node.parent == nil ? -1 : node.parent->id) << ", ";
		cout << "depth = " << node.depth << ", ";
		k = node.childs.size();
		if(node.parent == nil){
			cout << "root";
		}else if(k == 0){
			cout << "leaf";
		}else{
			cout << "internal node";
		}
		cout << ", [";
		if(k > 0){
			cout << node.childs[0]->id;
			for(int i = 1; i < k; i++){
				cout << ", " << node.childs[i]->id;
			}
		}
		cout << "]" << endl;
	}

	return 0;
}
