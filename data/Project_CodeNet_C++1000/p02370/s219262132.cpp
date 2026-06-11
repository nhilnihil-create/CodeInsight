#include<iostream>
#include<vector>
using namespace std;
vector<int> u[10010];
int n,m,t[10010],d[10010];
void dfs(int p){
	cout<<p<<"\n";
	for(int i=0;i<u[p].size();i++){
		d[u[p][i]]++;
		if(d[u[p][i]]==t[u[p][i]]){
			dfs(u[p][i]);	
			d[u[p][i]]=1008610086;
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		u[a].push_back(b);
		t[b]++;
	}
	for(int i=0;i<n;i++) if(t[i]==0) dfs(i);
	return 0;
}