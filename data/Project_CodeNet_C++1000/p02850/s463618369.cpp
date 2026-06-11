#include<bits/stdc++.h>
//#include<iostream>
using namespace std;

typedef long long ll;

const int N = 200005;

int n;
vector<pair<int,int> > adj[N];
int ans[N];

int k = 0;

void dfs(int x,int par,int c){
	int cnt = 1;
	k = max(k,(int)adj[x].size());
	for(auto p:adj[x]){
		int y = p.first,idx = p.second;
		if(y == par)continue;
		if(cnt == c)cnt++;
		ans[idx] = cnt;
		dfs(y,x,cnt);
		cnt++;
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back({y,i});
		adj[y].push_back({x,i});
	}
	
	dfs(1,1,0);
	
	cout<<k<<endl;
	for(int i=1;i<n;i++){
		cout<<ans[i]<<endl;
	}
	
	
	return 0;
}
