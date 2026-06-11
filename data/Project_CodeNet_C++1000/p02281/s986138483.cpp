#include <cstdio>
#include <vector>

#define MAX(a,b) ((a)>(b)?(a):(b))

using namespace std;


struct BINNODE {
	int parent;
	int degree;
	int sibling;
	int left;
	int right;

	BINNODE () { // default constructor
		parent=-1;
		degree=0;
		sibling=-1;
		left=-1;
		right=-1;
	}
};


void preorderwalk(vector<BINNODE>& node, int root) {
	if(root==-1) return;
	printf(" %d",root);
	preorderwalk(node,node[root].left);
	preorderwalk(node,node[root].right);
	return;
}

void inorderwalk(vector<BINNODE>&node, int root) {
	if(root==-1) return;
	inorderwalk(node,node[root].left);
	printf(" %d",root);
	inorderwalk(node,node[root].right);
	return;
}

void postorderwalk(vector<BINNODE>&node, int root) {
	if(root==-1) return;
	postorderwalk(node,node[root].left);
	postorderwalk(node,node[root].right);
	printf(" %d",root);
	return;
}

int main() {
	int n;
	int i;
	int id,left,right,root;
	vector<BINNODE> node;
	scanf("%d",&n);
	node.resize(n);
	for(i=0; i<n; ++i) {
		scanf("%d%d%d",&id,&left,&right);
		node[id].left=left;
		node[id].right=right;
		if(left==-1 && right==-1) {
			node[id].degree=0;
		} else if(left==-1) {
			node[id].degree=1;
			node[right].parent=id;
			node[right].sibling=-1;
		} else if(right==-1) {
			node[id].degree=1;
			node[left].parent=id;
			node[left].sibling=-1;
		} else {
			node[id].degree=2;
			node[left].parent=id;
			node[right].parent=id;
			node[left].sibling=right;
			node[right].sibling=left;
		}
	}
	for(i=0; i<n; ++i) {
		if(node[i].parent==-1) root=i;
	}
	printf("Preorder\n");
	preorderwalk(node,root);
	printf("\n");
	printf("Inorder\n");
	inorderwalk(node,root);
	printf("\n");
	printf("Postorder\n");
	postorderwalk(node,root);
	printf("\n");
	return 0;
}