#include <stdio.h>
#include <vector>

using namespace std;

struct Node{
	Node(){
		parent = -1;
		depth = num_of_children = 0;
	}
	int parent;
	int depth;
	vector<int> children;
	int num_of_children;
};

void calcDepth(Node nodes[],int root_id){
	for(int i = 0;i < nodes[root_id].num_of_children;i++){
		nodes[nodes[root_id].children[i]].depth = nodes[root_id].depth+1;
		calcDepth(nodes,nodes[root_id].children[i]);
	}
}

int main(){
	int n,id,k,child_id,root_id;
	scanf("%d",&n);
	Node nodes[n];

	for(int i = 0; i < n; i++){
		scanf("%d %d",&id,&k);
		for(int j = 0; j < k; j++){
			scanf("%d",&child_id);
			nodes[id].children.push_back(child_id);
			nodes[id].num_of_children++;
			nodes[child_id].parent = id;
		}
	}

	for(root_id = 0; root_id < n; root_id++){
		if(nodes[root_id].parent == -1) break;
	}

	calcDepth(nodes,root_id);

	for(int i = 0; i < n; i++){
		if(nodes[i].parent == -1){
			printf("node %d: parent = -1, depth = 0, root, ",i);
		}else if(nodes[i].num_of_children == 0){
			printf("node %d: parent = %d, depth = %d, leaf, ",i,nodes[i].parent,nodes[i].depth);
		}else{
			printf("node %d: parent = %d, depth = %d, internal node, ",i,nodes[i].parent,nodes[i].depth);
		}
		printf("[");
		for(int j = 0; j < nodes[i].num_of_children-1; j++){
			printf("%d, ",nodes[i].children[j]);
		}
		if(nodes[i].num_of_children > 0){
			printf("%d",nodes[i].children[nodes[i].num_of_children-1]);
		}
		printf("]\n");
	}
}