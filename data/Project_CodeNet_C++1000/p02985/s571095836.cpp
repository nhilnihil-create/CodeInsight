#include<bits/stdc++.h>
#define all(x) x.begin(),x.end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD=1e9+7;
const ll LINF=1e18;
const int INF=0x3f3f3f3f;
const int MAXN=100050;

ll ans,k;
vector<ll>G[MAXN];
void dfs(ll now,ll fa,ll dep,ll us){
	int sum=0;
	ans*=(k-min(dep,2ll)-us);
	ans%=MOD;
	for(ll i=0;i<G[now].size();i++){
		if(G[now][i]==fa)continue;
		
		dfs(G[now][i],now,dep+1,sum);
		sum++;
	}
}
void solve(int T){
	ll n,u,v;
	scanf("%lld %lld",&n,&k);
	ans=1;
	for(int i=1;i<n;i++){
		scanf("%lld %lld",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1ll,0,0,0);
	printf("%lld\n",ans);
}
signed main(){
	int t=1;
	//scanf("%lld",&t); 
	for(int i=1;i<=t;i++){
		solve(i);
	}
}