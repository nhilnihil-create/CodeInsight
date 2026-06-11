#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define MO 1000000007
#define mem(a,s) memset(a,s,sizeof(a))
#define IOS ios_base::sync_with_stdio(0); cin.tie(NULL);
#define lop(i,s,e) for(int i=s;i<e;i++)
#define lopi(i,s,e) for(int i=s;i>=e;i--)
#define prina(a,n) for(int i=0;i<=n;i++)cout<<a[i]<<" ";cout<<endl; 
#define prin2da(a,n,m) lop(i,1,n){lop(j,1,m)cout<<a[i][j]<<" ";cout<<endl;}
#define atout(v) for(auto x:v) cout<<x<<" ";cout<<endl;
#define atin(v) for(auto &x:v) cin>>x;
#define vl vector<ll >
#define vi vector<int >
#define lb lower_bound
#define ub upper_bound
#define sort(a) sort(a.begin(),a.end())  
#define mp make_pair
#define all(v) v.begin(),v.end() 
#define pll pair<ll,ll>
using namespace std;

void dfs(vector<vector<ll>> &g, vector<bool> &visited, ll node) {
	visited[node]=true;
	for(auto x:g[node]) {
		if(!visited[x]) {
			dfs(g,visited,x);
		}
	}
	return;
}

void solve() {
	ll n,m;
	cin>>n>>m;
	vector<vector<ll>> g(n+1);
	lop(i,0,m) {
		ll u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	vector<bool> visited(n+1,false);
	ll ans=0;
	lop(i,1,n+1) {
		if(!visited[i]) {
			ans++;
			dfs(g,visited,i);
		}
	}
	cout<<ans-1<<endl;
	return;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

	ll t=1;
	while(t--) {
		solve();
	}

	return 0;
}