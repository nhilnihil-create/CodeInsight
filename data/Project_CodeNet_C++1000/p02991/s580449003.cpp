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

int N,M,S,T;
vi adj[maxn];
vpi adj2[maxn];
bool vis[maxn][3];
int dist[maxn][3];
vpi nodes[3];

int main(){
	fast;
	
	cin>>N>>M;
	
	FOR(i,0,M-1){
		int a,b; cin>>a>>b; adj[a].pb(b);
	}
	
	cin>>S>>T;
	

		
	queue <pi> q;
	q.push(pi(S,0));
		
	while (!q.empty()){
		pi cur = q.front(); q.pop();
			
		if (vis[cur.f][cur.s%3]) continue;
		vis[cur.f][cur.s%3] = 1;
		
		dist[cur.f][cur.s%3] = cur.s;
		aFOR(i,adj[cur.f]){
			q.push(pi(i,cur.s+1));
		}
	}
	
	if (vis[T][0] == 1) cout<<dist[T][0]/3;
	else cout<<-1;

		
}