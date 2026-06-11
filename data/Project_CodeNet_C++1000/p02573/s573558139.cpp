#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll P = 1e9+7;
const ll N = 2e5+7;

vector<ll> g[N];
vector<ll> vis(N);

void dfs(ll node, ll mark){
	vis[node] = mark;

	for(auto &x : g[node]){
		if(!vis[x]){
			dfs(x,mark);
		}
	}
}


int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t=1;
	// cin>>t;

	while(t--){
		ll n,m;
		cin>>n>>m;

		
		ll a,b;
		for(ll i=0;i<m;++i){
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		vector<ll>hash(n+7);
		a = 1;
		for(ll i=1;i<=n;++i){
			if(!vis[i]) dfs(i,a++);
		}

		for(auto &x : vis) hash[x]++;
		a = 0;
		for(ll i=1;i<=n;++i) a = max(a,hash[i]);

		cout<<a<<"\n";

	}	

	return 0;
}	