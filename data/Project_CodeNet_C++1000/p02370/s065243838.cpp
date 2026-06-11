#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define MAXN 10000+2
int topo[MAXN],n,m,t;
int c[MAXN];
vector<int> map1[MAXN];
void input(){
	cin>>n>>m;
	int xx,yy;
	for(int i=0;i<m;++i){
	    cin>>xx>>yy;
	    map1[xx].push_back(yy);
	}
}
void dfs(int u){
	c[u]=-1;
	for(int i=0;i<map1[u].size();++i){
		if(!c[map1[u][i]]) dfs(map1[u][i]);
	}
	c[u]=1;
	topo[--t]=u;
}
void jl(){
	t=n;
	for(int i=n-1;i>=0;--i){
		if(!c[i]) dfs(i);
	}
	for(int i=0;i<n-1;++i){
		cout<<topo[i]<<" ";
	}
	cout<<topo[n-1]<<endl;
}
int main(){
	input();
	jl();
	return 0;
}