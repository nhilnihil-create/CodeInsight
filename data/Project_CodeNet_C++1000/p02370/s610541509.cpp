#include<bits/stdc++.h>
using namespace std;
#define MAX_V 100000
#define rep(i,n) for(int i=0;i<n;i++)
vector<int> ans;
vector<int>  g[MAX_V];

void dfs(vector<bool>& used,int s){
	used[s] = false;
	rep(i,g[s].size() ){
	if(used[g[s][i]])	{
		dfs(used,g[s][i]);
	//	cout<<i<<endl;
	}
	}
	ans.push_back(s);
	return;
}
void	tsort(int v){
	vector<bool> used(v,true);
	rep(i,v){
	if(used[i]){
	dfs(used,i);
	}
	}
	//rep(i,v)if(used[i])cout<<i<<endl;
	return ;
}
int main(){
	int v,e;
	cin>>v>>e;
	//vector<vector<int> > g(v);	
	int s,t;
	rep(i,e){
	cin>>s>>t;
	g[s].push_back(t);
	}
	tsort(v);
	for(int i=ans.size()-1;i>=0;i--)cout<<ans[i]<<endl;	

return 0;
}


