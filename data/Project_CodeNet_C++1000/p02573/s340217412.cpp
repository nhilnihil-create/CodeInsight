#include<bits/stdc++.h>

using namespace std;

const int MAX = 2 * 1000 * 100 + 11;
int parent[MAX];
int sizeOfSet[MAX];
int n, m;

void make_set(int node) {
	parent[node] = node;
	sizeOfSet[node] = 1;
}

int find_set(int node) {
	if(node == parent[node]) {
		return node;
	}
	
	return parent[node] = find_set(parent[node]);
}

void union_sets(int firstNode, int secondNode) {
	int parentOfFirstNode = find_set(firstNode);
	int parentOfSecondNode = find_set(secondNode);
	
	if(parentOfFirstNode != parentOfSecondNode) {
		if(sizeOfSet[parentOfFirstNode] < sizeOfSet[parentOfSecondNode])
			swap(parentOfFirstNode, parentOfSecondNode);
			
		parent[parentOfSecondNode] = parentOfFirstNode;
		
		sizeOfSet[parentOfFirstNode] += sizeOfSet[parentOfSecondNode];
	}
}

map<int, int> mp;

int main()
{
	cin >> n >> m;
	
	for(int i = 0; i < n; i++) {
		make_set(i);
	}
	
	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		union_sets(x, y);
	}
	
	for(int i = 1; i <= n; i++) {
		mp[find_set(i)]++;
	}
	
	int res = 0;
	for(auto it: mp) {
		res = max(res, it.second);
	}
	
	cout << res;
	return 0;
}
