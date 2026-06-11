#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<list>
using namespace std;
vector < int > G[1000000];
list < int > out;
bool v[1000000];
int n;
int indeg[1000000];
void bfs(int u){
	queue < int > Q;
	Q.push(u);
	v[u]=1;
	while(!Q.empty()){
		int k=Q.front();
		Q.pop();
		out.push_back(k);
		v[k]=1;
		for(int i=0;i<G[k].size();i++){
			int p=G[k][i];
			indeg[p]--;
			if(indeg[p]==0&&!v[p]) Q.push(p);
		}
	}
}
void f(){
	for(int i=0;i<n;i++){
		for(int j=0;j<G[i].size();j++){
			int v=G[i][j];
			indeg[v]++;
		}
	}
	for(int i=0;i<n;i++){
		if(!v[i]&&indeg[i]==0) bfs(i);
	}
	for(list<int >::iterator it=out.begin();it!=out.end();it++){
		printf("%d\n",*it);
	}
	
}
int main(){
	int s,t,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&s,&t);
		G[s].push_back(t);
	}
	f();
	return 0;
}
