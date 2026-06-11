#include <bits/stdc++.h>
using namespace std;

typedef struct node{
	int parent;
	int rank;
	int size;
}node;

int find(vector<node> &nodes, int x){
	if(x == (nodes[x].parent))
		return x; // found the root of this tree
	else {
		nodes[x].parent = find(nodes, nodes[x].parent); // path compression
		return nodes[x].parent;
	}
}

void doUnion(vector<node> &nodes, int x, int y){
	int rootX = find(nodes, x);
	int rootY = find(nodes, y);
	if(rootX == rootY)
		return;
	else if(nodes[rootX].rank > nodes[rootY].rank){
		nodes[rootY].parent = nodes[rootX].parent;
		nodes[rootX].size = nodes[rootX].size + nodes[rootY].size;
	}
	else if(nodes[rootX].rank < nodes[rootY].rank){
		nodes[rootX].parent = nodes[rootY].parent;
		nodes[rootY].size = nodes[rootX].size + nodes[rootY].size;
	}
	else{
		nodes[rootX].parent = nodes[rootY].parent;
		nodes[rootY].rank = nodes[rootY].rank + 1;
		nodes[rootY].size = nodes[rootX].size + nodes[rootY].size;
	}
}

int main(){
	int N, M;
	int x,y;

	cin >> N >> M;
	vector<node> nodes;
	nodes.push_back({-1, -1, 0});

	for (int i=1;i<N+1;i++)
		nodes.push_back({i, 0, 1});

	for(int i=1;i<=M;i++){
		cin >> x >> y;
		doUnion(nodes, x, y);
	}
	int res = 1;
	for(int i=1;i<=N;i++)
		res = max(res, nodes[i].size);

	cout << res << "\n";
	return 0;
}