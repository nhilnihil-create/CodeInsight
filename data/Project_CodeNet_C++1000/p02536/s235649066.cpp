#include<bits/stdc++.h>

using namespace std;

#define INF 1e9
#define rep(i,a,n) for(ll i=(a);i<(n);i++)
#define repv(i,a,n) for(ll i=(n)-1;i>=a;i--)
#define ll long long int
#define endl "\n"
#define pb push_back

vector<int> adj[1000005];
bool vis[1000005];

void dfs(int i) {
	vis[i] = true;
	for(auto child:adj[i]) {
		if(!vis[child])
			dfs(child);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

   	int n, m;
   	cin >> n >> m;
   	rep(i,0,m) {
   		int a, b;
   		cin >> a >> b;
   		adj[a].pb(b);
   		adj[b].pb(a);
   	}
   	int c = 0;
   	rep(i,1,n+1) {
   		if(!vis[i]) {
   			c++;
   			dfs(i);
   		}
   	}
   	c--;
   	cout << c;
}

