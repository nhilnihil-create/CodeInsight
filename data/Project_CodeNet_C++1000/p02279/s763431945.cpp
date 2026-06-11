#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <list>

long long int INF = 1e18;
using namespace std;

typedef pair<long long int, long long int> P;

vector<int> E[110000];
int parent[110000];
int depth[110000];

void f(int u, int d){
	depth[u] = d;
	for(int i = 0; i < E[u].size(); i++){
		f(E[u][i], d + 1);
	}
}

int main(){
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++){
		parent[i] = -1;
	}
	
	for(int i = 0; i < n; i++){
		int id, num;
		cin >> id >> num;
		for(int j = 0; j < num; j++){
			int c;
			cin >> c;
			E[id].push_back(c);
			parent[c] = id;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(parent[i] == -1){
			f(i, 0);
			break;
		}
	}
	
	for(int i = 0; i < n; i++){
		cout << "node " << i << ": parent = " << parent[i];
		cout << ", depth = " << depth[i] << ", ";
		if(parent[i] == -1){
			cout << "root";
		}else if(E[i].size() == 0){
			cout << "leaf";
		}else{
			cout << "internal node";
		}
		cout << ", [";
		if(E[i].size() > 0){
			cout << E[i][0];
		}
		for(int j = 1; j < E[i].size(); j++){
			cout << ", " << E[i][j];
		}
		cout << "]" << endl;
	}
	return 0;
}
