#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod = 1e9+7;
const int N = 1e5;
ll npr1[N+100],npr2[N+100];
vector<int>graph[N+100];
int deg[N+100];
void dfs(int u,int p)
{
	for(auto it:graph[u])
	{
		if(it!=p){
			deg[u]++;
			dfs(it,u);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<n;i++){
		int u,v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(1,-1);
	npr1[0] = 1,npr2[0] = 1;
	for(int i=1;i<=k;i++){
		npr1[i] = (npr1[i-1]*(k-i+1))%mod;
	}
	for(int i=1;i<=k-2;i++){
		npr2[i] = (npr2[i-1]*(k-2-i+1))%mod;
	}
	deg[1]++;
	ll ans = npr1[deg[1]];
	for(int i=2;i<=n;i++){
		ans = (ans*npr2[deg[i]])%mod;
	}
	cout << ans << "\n";
}
