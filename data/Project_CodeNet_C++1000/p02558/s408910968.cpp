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


int main()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		make_set(i);
	}
	
	int t; cin >> t;
	while(t--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(a == 0)
		{
			union_sets(b + 1, c + 1);
		}
		else
		{
			if(find_set(b+1) == find_set(c+1))
			{
				cout << '1' << endl;
			}
			else
			{
				cout << '0' << endl;
			}
		}
	}
	return 0;
}
