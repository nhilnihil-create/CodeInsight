#include <iostream>
#include <vector>
#include <list>
#define N 10000
using namespace std;

list<int> l;
bool color[N]={false};
vector<int> adj[N];
int n;

void topo(int k){
	for(int i=0;i<adj[k].size();i++){
		if(!color[adj[k][i]])topo(adj[k][i]);
	}
	if(!color[k])l.push_front(k);
	color[k]=true;
}

int main(void){
	int u,v;
	int e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		cin>>u>>v;
		adj[u].push_back(v);	
	}
	for(int i=0;i<n;i++){
		if(!color[i])topo(i);
	}
	for(list<int>::iterator it=l.begin();it!=l.end();it++)cout<<*it<<endl;
	return 0;
}