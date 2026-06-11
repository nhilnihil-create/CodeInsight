#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 2e5+5;
vector<int> graph[M];
bool vis[M]={0};
int dfs(int i){
	vis[i]=1;
	int cnt = 1;
	for(auto node:graph[i]){
		if(!vis[node]){
			cnt+=dfs(node);
		}
	}
	return cnt;
}
int main(){
	//freopen("test.in","r",stdin);
	int n,m;
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int res = 0;
	for(int i=1;i<=n;i++){
		if(!vis[i])res = max(res,dfs(i));
	}
	cout<<res<<endl;
    return 0;
}
