#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define pb push_back
vector<vector<int>>adj;
main() {
	string s;
	cin>>s;
	int n=s.size()+1;
	adj.resize(n);
	int ind[n];
	int val[n];
	for(int i=0; i<n; i++){
		ind[i]=0;
		val[i]=0;
	}
	for(int i=0; i<s.size(); i++){
		if(s[i]=='<'){
			adj[i].pb(i+1);
			ind[i+1]++;
		}
		else{
			adj[i+1].pb(i);
			ind[i]++;
		}
	}
	queue<int>q;
	for(int i=0; i<n; i++){
		if(ind[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(auto u:adj[node]){
			val[u]=1+val[node];
			q.push(u);
		}
	}
	int sum=0;
	for(int i=0; i<n; i++){
		sum+=val[i];
	}
	cout<<sum;
	return 0;
}