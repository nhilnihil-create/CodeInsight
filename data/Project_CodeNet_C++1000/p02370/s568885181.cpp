#include<bits/stdc++.h>
using namespace std;
vector<int> a[10001];
vector<int> b;
list<int> q;
bool vis[10001];
int v,e,x,y;
void dfs(int x){
	 vis[x]=true;
	 for (int i=0; i<a[x].size(); i++){
	 	 if (!vis[a[x][i]])
	 	    dfs(a[x][i]);
	 }
	 q.push_back(x);
}
int main(){
	memset(vis,false,sizeof(vis));
	cin>>v>>e;
	for (int i=0; i<e; i++){
		cin>>x>>y;
		a[x].push_back(y); 
	}
	for (int i=0; i<v; i++){
		if (!vis[i])
		   dfs(i); 
	}
	for (list<int>::iterator it=q.begin(); it!=q.end(); it++)
	     b.push_back(*it);
	reverse(b.begin(),b.end());
	cout<<b[0];
	for (int i=1; i<b.size(); i++)
	    cout<<' '<<b[i];
	cout<<'\n';
	return 0;
}
