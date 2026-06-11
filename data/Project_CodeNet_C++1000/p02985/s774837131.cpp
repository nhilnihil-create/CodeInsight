#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector <ll> vi;
typedef vector <pi> vpi;
#define f first
#define s second
#define FOR(i,s,e) for(ll i=s;i<=ll(e);++i)
#define DEC(i,s,e) for(ll i=s;i>=ll(e);--i)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lbd(x, y) lower_bound(all(x), y)
#define ubd(x, y) upper_bound(all(x), y)
#define aFOR(i,x) for (auto i: x)
#define mem(x,i) memset(x,i,sizeof x)
#define fast ios_base::sync_with_stdio(false),cin.tie(0)
#define maxn 100001
#define MOD 1000000007
int N,K;
vi adj[maxn];
int par[maxn],depth[maxn],sz[maxn];
int ans[maxn];



int cur = 1;
void order(int x,int p){

	par[x] = p;
	aFOR(i,adj[x]){
		if (i != p){
			depth[i] = depth[x]+1;
			order(i,x);
		}
	}
}



void dfs(int x,int p){
	if (p == -1) ans[x] = K;
	else{
		int num = 0;
		if (depth[x] > 1) num = 2;
		else num = 1;
		
		
		num += sz[par[x]];
		
		ans[x] = K - num;
	}
	sz[par[x]]++;
	aFOR(i,adj[x]){
		if (i != p) dfs(i,x);
	}
	//sz[x]++;
}
		
int main(){
	fast;
	
	cin>>N>>K;
	
	FOR(i,0,N-2){
		int a,b;cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	order(1,-1);

	
	dfs(1,-1);
	
	ll lans = 1;
	FOR(i,1,N){
		//cout<<ans[i]<<' ';
		lans *= ans[i];
		lans %= MOD;
	}
	
	cout<<max(lans,(ll)0);
	
	
}

