#include <bits/stdc++.h>
using namespace std;
int main(){
	int v, e;
	cin >> v >> e;
	vector<vector<int>> elist(v);
	vector<int> indeg(v);
	for(int i=0; i<e; ++i){
		int s, t;
		cin >> s >> t;
		elist[s].push_back(t);
		++indeg[t];
	}
	queue<int> zeroq;
	for(int i=0; i<v; ++i){
		if(indeg[i]==0) zeroq.push(i);
	}
	vector<int> result;
	while(!zeroq.empty()){
		int u=zeroq.front();
		zeroq.pop();

		result.push_back(u);
		for(int i : elist[u]){
			--indeg[i];
			if(indeg[i]==0) zeroq.push(i);
		}
	}

	for(int i : result) cout << i << endl;
}
