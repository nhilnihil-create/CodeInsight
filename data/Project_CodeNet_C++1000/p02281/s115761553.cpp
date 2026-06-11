#include <bits/stdc++.h>
using namespace std;
#define r(i,n) for(auto i=0;i<n;i++)

struct Node{
	int id;
	int depth;
	int height;
	Node *parent;
	vector<Node*> childs;

    bool operator<( const Node& param ) const {
        return id < param.id;
    }
};
Node *nil;

list<int> ids;
map<int, list<int>> getChilds;

void conChilds(Node *node){
	for(int childId : getChilds[node->id]){
		if(childId != -1){
			Node *child = new Node();
			child->id = childId;
			child->depth = node->depth + 1;
			child->parent = node;
			(node->childs).push_back(child);
			conChilds(child);
		}else{
			(node->childs).push_back(nil);
		}
	}

	int maxHeight = -1;
	for(Node *child : node->childs){
		if(child != nil)
			maxHeight = max(maxHeight, child->height);
	}
	node->height = maxHeight+1;
}

list<int> preorderList;
void preorder(Node *node){
	auto childs = node->childs;
	int k = childs.size();
	preorderList.push_back(node->id);
	if(k > 0 && childs[0] != nil) preorder(childs[0]);
	if(k > 1 && childs[1] != nil) preorder(childs[1]);
}

list<int> inorderList;
void inorder(Node *node){
	auto childs = node->childs;
	int k = childs.size();
	if(k > 0 && childs[0] != nil) inorder(childs[0]);
	inorderList.push_back(node->id);
	if(k > 1 && childs[1] != nil) inorder(childs[1]);
}

list<int> postorderList;
void postorder(Node *node){
	auto childs = node->childs;
	int k = childs.size();
	if(k > 0 && childs[0] != nil) postorder(childs[0]);
	if(k > 1 && childs[1] != nil) postorder(childs[1]);
	postorderList.push_back(node->id);
}

int main(){
	int n, id, t, maxId = 25;
	cin >> n;

	r(i, n){
		cin >> id;
		ids.push_back(id);
		list<int> childs;
		maxId = max(maxId, id);

		cin >> t;
		childs.push_back(t);
		cin >> t;
		childs.push_back(t);

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

	preorder(root);
	inorder(root);
	postorder(root);

	printf("Preorder\n");
	for(int i : preorderList) printf(" %d", i);
	printf("\nInorder\n");
	for(int i : inorderList) printf(" %d", i);
	printf("\nPostorder\n");
	for(int i : postorderList) printf(" %d", i);
	printf("\n");

	return 0;
}

