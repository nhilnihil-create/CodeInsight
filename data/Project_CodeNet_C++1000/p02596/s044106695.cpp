#include<bits/stdc++.h>    
using namespace std;
#define ll long long 
#define pi pair<ll,ll>
#define pd pair<ld,ld>
#define pb push_back
#define inf 1e15
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
const ll MAXN = 1e5+5;
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
	ll k;cin>>k;
	bool dp[k+1];ms(dp);
	ll ans = 0 ;
	ll sub = 0 ;  
	bool flag = true;
	while(true){
		sub = sub*10+7;
		sub%=k;
		ans++;
		if(sub==0)break;
		if(dp[sub]){
			flag = false;
			break;
		}
		dp[sub]=true;
	}
	if(flag)cout<<ans<<en;
	else cout<<-1<<en;
	return 0 ;

}