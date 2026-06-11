#include <iostream>
using namespace std;

class Node{
public:
	int depth;
	
	int parent;
	
	int degree;
	int *children;
	
	
};

void Depth(Node *node,int cur, int dp){
	
	node[cur].depth = dp;
	
	
	for(int i=0;i<node[cur].degree;++i){
		Depth(node,node[cur].children[i],dp+1);
	}
	
}

int main() {
	
	int n;
	Node *node;
	
	cin>>n;
	node = new Node[n];
	for(int i=0;i<n;++i)node[i].parent = -1;
	
	
	for(int i=0;i<n;++i){
		int id,k;
		
		cin>>id;
		cin>>k;
		node[id].degree = k;
		
		node[id].children = new int[k];
		for(int j=0;j<k;++j){
			int cid;
			cin>>cid;
			node[id].children[j] = cid;
			node[cid].parent = id;
		}
	}
	
	int root;
	for(int i=0;i<n;++i)if(node[i].parent == -1)root = i;
	
	Depth(node,root,0);
	
	for(int i=0;i<n;++i){
		cout<<"node "<<i<<": parent = "<<node[i].parent<<", depth = "<<node[i].depth<<
		", "<<( i==root?"root": ( node[i].degree == 0 ? "leaf" : "internal node" ) )<<", [";
		
		for(int j=0;j<node[i].degree;++j){
			cout<<(j?", ":"")<<node[i].children[j];
		}
		cout<<"]"<<endl;
	}
	
	return 0;
}