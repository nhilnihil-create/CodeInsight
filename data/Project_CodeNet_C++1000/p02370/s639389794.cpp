#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<int> G[100000];
bool vis[100000];
vector<int> ord;

void visit(int n){
	if(!vis[n]){
		vis[n] = true;
		for(int i = 0; i < G[n].size(); i++){
			visit(G[n][i]);
		}
		ord.push_back(n);
		//cout << n;
	}
}

int main(){
	
	int V, E;
	cin >> V >> E;
	
	for(int i = 0; i < E; i++){
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
	}
	
	for(int i = 0; i < V; i++){
		visit(i);
	}
	
	reverse(ord.begin(), ord.end());
	
	for(int i = 0; i < ord.size(); i++){
		cout << ord[i] << endl;
	}
	
	return 0;
}
