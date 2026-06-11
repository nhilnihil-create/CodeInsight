#include<bits/stdc++.h>
using namespace std;

vector<int> g[200005];
vector<int> ans;
bool vis[200005];
void dfs(int s,int& cnt){
	if(vis[s]) return;
	vis[s] = true;
	cnt++;
	for(int i=0;i<g[s].size();i++){
		if(vis[g[s][i]]) continue;
		dfs(g[s][i],cnt);
	}
}
int main(int argc, char * argv[]) 
{
	int n,m,a,b;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++){
		if(!vis[i]){
			int cnt = 0;
			dfs(i,cnt);
			ans.push_back(cnt);
			//printf("i=%d,cnt=%d\n",i,cnt);
		}
	}
	int realAns = ans[0];
	for(int i=0;i<ans.size();i++)
		realAns = max(realAns,ans[i]);
	cout<<realAns<<endl;
    return 0;
}