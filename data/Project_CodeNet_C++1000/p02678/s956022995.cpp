#include<bits/stdc++.h>    
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define pd pair<ld,ld>
#define pb push_back
#define inf 1e18
#define mod 1000000007
#define en '\n'
#define ld long double
#define ff first
#define ss second
#define ull unsigned long long 
#define lb lower_bound
#define ub upper_bound
#define fr(a,b,c) for(ll a = b ; a <= c ; ++a )
#define frn(a,b,c) for(ll a = b ; a >= c ; a -- )
#define fra(a,b) for(auto a: b)
#define ms(a) memset(a,0,sizeof a);
#define alla(a) a,a+n
#define allv(a) a.begin(),a.end()
#define size(a) (ll)a.size()
#define getMat(x,n,m,val) vector<vector<ll>>x(n,vector<ll>(m,val))
const ll MAXN = 1000005;
#define pii 3.14159265358979323846
 
ll pw(ll b, ll r, ll md){
	ll ans = 1;
	while(r){
		if(r&1)ans = (ans*b)%md;
		b = (b*b)%md;
		r>>=1;
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;cin>>n>>m;
	vector<ll>g[n+1];
	fr(i,0,m-1){
		ll a,b;cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	ll ans[n+1];ms(ans);
	queue<ll>q;
	q.push(1);
	ans[1]=1;
	while(!q.empty()){
		ll u = q.front();
		q.pop();
		for(auto v: g[u]){
			if(!ans[v]){
				q.push(v);
				ans[v]=u;
			}
		}
	}
	bool flag = false;
	fr(i,1,n)if(!ans[i])flag=true;
	if(flag)cout<<"No\n";
	else {
		cout<<"Yes\n";
		fr(i,2,n)cout<<ans[i]<<en;
	}
	return 0 ;
}