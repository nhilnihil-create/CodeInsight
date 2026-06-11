#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int INF = 1e9;
const int S = 3e5;

vector<int> adj[S];
int n;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for (int i = 0; i < n-1; i++){
		int u, v;
		cin>>u>>v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++){
		ans += i*(n-i+1);
	}
	for (ll i = 0; i < n; i++){
		for (ll it: adj[i]){
			if (it < i){
				ans -= (it+1)*(n-i);
				// cout<<i+1<<" "<<it+1<<": "<<ans<<'\n';
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}