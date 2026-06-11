#include <bits/stdc++.h>
using namespace std;

int n,m,u,v;
vector<int>e[100005];
int d[100005];
int main(){
//	freopen("a.txt","r",stdin);
	cin.tie(0);
	cin>>n>>m;
	while(m--){
		cin>>u>>v;
		e[u].push_back(v);
		d[v]++;
	}
	queue<int>q;
	for(int i=0;i<n;i++)if(d[i]==0)q.push(i);
	while(!q.empty()){
		cout<<q.front()<<endl;
		for(int i=0;i<e[q.front()].size();i++){
			--d[e[q.front()][i]];
			if(d[e[q.front()][i]]==0)q.push(e[q.front()][i]);
		}
		q.pop();
	}
	return 0;
}
