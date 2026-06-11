#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
	
	int n,m; cin>>n>>m;
	vector<vector<int>> e(n);
	for(int i=0; i<m; i++){
		int u,v; cin>>u>>v;
		e.at(--u).push_back(--v);
	}
	int s,t; cin>>s>>t;
	--s; --t;
	vector<vector<int>> d(n,vector<int>(3,-1));
	d.at(s).at(0) = 0;
	queue<pair<int,int>> q;
	q.push({s,0});
	while(!q.empty()){
		auto p = q.front();
		q.pop();
		for(auto i:e.at(p.first)){
			if(d.at(i).at((p.second+1)%3)==-1){
				d.at(i).at((p.second+1)%3) = d.at(p.first).at(p.second)+1;
				q.push({i,(p.second+1)%3});
			}
		}
	}
	if(d.at(t).at(0)==-1) d.at(t).at(0)=-3;
	cout << d.at(t).at(0)/3 << endl;
}

