#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(998244353)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
ll gcd(ll a,ll b){if(!b)return a;else return gcd(b,a%b);}
int main()
{
	int n,m;
	cin>>n>>m;
	vii adj(3*n);
	vector<ll>dist(3*n,-1);
	for(int i=0;i<m;i++){
		int v,u;
		cin>>v>>u;
		v--;u--;
		for(int j=0;j<3;j++){
			adj[v+j*n].pb(u+((j+1)%3)*n);
		}
	}
	int s,t;
	cin>>s>>t;
	s--;t--;
	queue<int>q;
	q.push(s);
	dist[s] = 0;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int x:adj[v]){
		    if(dist[x] == -1){
				dist[x] = dist[v]+1;
				q.push(x);
			}
		}
	}
	if(dist[t] == -1)cout<<-1;
	else cout<<dist[t]/3;
}
