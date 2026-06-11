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
typedef long double ld;
#define maxn 200001

int N,Q;
vi adj[maxn];
int st[maxn],en[maxn];

int fw[maxn];
int cur = 1;

void upd(int p,int v){ //update position p by +=v
	for (int i=p; i<=N; i+= (i&(-i))){
		fw[i] += v;
	}
}


void update_range(int a,int b, int c){ //update position a to b by +=c
	upd(a,c); //upd function from the PURQ fenwick
upd(b+1,-c);
}

int qry(int p){ //query p
	int ans = 0;
	for (int i = p; i>0; i -= (i&(-i))){
		ans += fw[i];
	}
	return ans;
}



void dfs(int x,int p){
	st[x] = cur++;
	aFOR(i,adj[x]) if (i != p) dfs(i,x);
	en[x] = cur - 1;
}
int32_t main()
{
	cin>>N>>Q;
	
	FOR(i,1,N-1){
		int a,b; cin>>a>>b;
		adj[a].pb(b); adj[b].pb(a);
	}
	dfs(1,-1);
	
	FOR(i,1,Q){
		int p,x; cin>>p>>x;
		
		update_range(st[p],en[p],x);
	}
	
	FOR(i,1,N) cout<<qry(st[i])<<' ';
}
