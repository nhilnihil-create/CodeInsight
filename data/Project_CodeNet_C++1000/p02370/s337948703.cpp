#include <bits/stdc++.h>
using namespace std;
#define dhoom ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);  
typedef long long ll;
#define SIZE 10005
vector< ll > dp[SIZE];
ll height[SIZE];
ll n ,m;
vector< int > graph[SIZE];
vector< int > ans;
vector< int > vis(SIZE,0);
void dfs(int u){
	vis[u] = true;
	for(auto v : graph[u])
	{
		if(!vis[v])
			dfs(v);
	}
	ans.push_back(u);
}
int main(){
	dhoom;
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++)
	{
		int u , v;
		cin >> u >> v;
		graph[u].push_back(v);
	}
	for(int i = 0 ;i < n ; i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	reverse(ans.begin() , ans.end());
	for(int i = 0 ;i < n ; i++)	
	{
		cout << ans[i] << endl;
	}
	
    return 0;
}


