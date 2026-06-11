#include <cstdio>
#include <vector>
#include <set>
using namespace std;

struct NODE {
	int id;
	int degree;
	int parent;
	int depth;
	vector<int> child;
};


int main() {
	vector<NODE> node;
	int n;
	int i,j;
	int id,k;
	scanf("%d",&n);
	node.resize(n);
	for(i=0; i<n; ++i) {
		scanf("%d%d",&id,&k);
		node[id].parent=-1; // default
		node[id].depth=0;   // default
		if(0==(node[id].degree=k)) {
			continue;
		}
		node[id].child.resize(k);
		for(j=0; j<k; ++j) {
			scanf("%d",&node[id].child[j]);
		}
	}
	for(i=0; i<n; ++i) {
		if((k=node[i].degree)==0) continue;
		for(j=0; j<k; ++j) {
			node[node[i].child[j]].parent=i;
		}
	}
	for(i=0; i<n; ++i) {
		j=i;
		while(node[j].parent!=-1){
			j=node[j].parent;
			++node[i].depth;
		}
	}
	for(i=0; i<n; ++i) {
		if(node[i].parent==-1) {
			printf("node %d: parent = %d, depth = %d, root, [",i,node[i].parent,node[i].depth);
			for(j=0; j<node[i].degree-1; ++j) {
				printf("%d, ",node[i].child[j]);
			}
			if(node[i].degree!=0) {
				printf("%d",node[i].child[j]);
			}
			printf("]\n");
		} else if(node[i].degree==0) {
			printf("node %d: parent = %d, depth = %d, leaf, [",i,node[i].parent,node[i].depth);
			for(j=0; j<node[i].degree-1; ++j) {
				printf("%d, ",node[i].child[j]);
			}
			if(node[i].degree!=0) {
				printf("%d",node[i].child[j]);
			}
			printf("]\n");
		} else {
			printf("node %d: parent = %d, depth = %d, internal node, [",i,node[i].parent,node[i].depth);
			for(j=0; j<node[i].degree-1; ++j) {
				printf("%d, ",node[i].child[j]);
			}
			if(node[i].degree!=0) {
				printf("%d",node[i].child[j]);
			}
			printf("]\n");
		}
	}
	return 0;
}