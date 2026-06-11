#include <bits/stdc++.h>
using namespace std;
int v,e;
vector<int> print;
vector<int> edge[10000];
int indeg[10000];
bool alrdy[10000];

void bfs(int start){
	queue<int> next;	next.push(start);
	while(!next.empty()){
		int ne=next.front();	next.pop();
		print.push_back(ne);
		alrdy[ne]=false;
		for(int i=0;i<(int)edge[ne].size();i++){
			int tem=edge[ne][i];
			if(alrdy[tem]&&indeg[tem]>0){
				indeg[tem]--;
				if(indeg[tem]==0){
					next.push(tem);
				}
			}
		}
	}
}

int main(){
	cin>>v>>e;
	for(int i=0;i<10000;i++){
		indeg[i]=0;	alrdy[i]=true;
	}
	int s,t;
	for(int i=0;i<e;i++){
		cin>>s>>t;
		edge[s].push_back(t);
		indeg[t]++;
	}
	for(int i=0;i<v;i++){
		if(alrdy[i]&&indeg[i]==0)	bfs(i);
	}
	for(vector<int>::iterator it=print.begin();it!=print.end();it++){
		cout<<*it<<endl;
	}
	return 0;
}