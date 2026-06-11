#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <climits>
using namespace std;

struct node {
	int parent;
	int leftChild;
	int right;
};

int checkDepth(node *nodes, node node){
	int i = 0;
	while(node.parent != -1){
		i++;
		node = nodes[node.parent];
	}
	return i;
}

int main() {
	int n;
	scanf("%d", &n);
	
	node *nodes = new node[1+n];
	for(int i = 0; i <= n; i++){
		nodes[i].parent = nodes[i].leftChild = nodes[i].right = -1;
	}
	
	for(int i = 0; i < n; i++){
		int id, k;
		scanf("%d %d", &id, &k);
		
		vector<int> v;
		for(int j = 0; j < k; j++){
			int child;
			scanf("%d", &child);
			v.push_back(child);
		}
		v.push_back(-1);
		
		for(int j = 0; j < k; j++){
			nodes[v[j]].parent = id;
			nodes[v[j]].right = v[j+1];
		}
		nodes[id].leftChild = v[0];
	}
	
	
	for(int i = 0; i < n; i++){
		printf("node %d: parent = %d, depth = %d, %s, [", i, nodes[i].parent, checkDepth(nodes, nodes[i]), nodes[i].parent == -1 ? "root" : nodes[i].leftChild == -1 ? "leaf" : "internal node");
		if(nodes[i].leftChild == -1) printf("]\n");
		for(int k = nodes[i].leftChild; k != -1; k = nodes[k].right){
			printf("%d%s", k, (nodes[k].right == -1 ? "]\n" : ", "));
		}
		
	}
	
	return 0;
}