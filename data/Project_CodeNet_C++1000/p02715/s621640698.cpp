/* * * * * * * * * * * **
*                      *
*	   saurabh8522	   *
*	  I will handle	   *
*		   IT.		   *
*                      *
* * * * * * * * * * * **/
#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ld long double
#define zero(a) memset((a),0,sizeof((a)))
#define one(a) memset((a),1,sizeof((a)))
#define minus(a) memset((a),-1,sizeof((a)))
#define all(g) g.begin(),g.end()
#define ppb pop_back
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b,ll m) {ll res=1;a%=m;for(;b;b>>=1){if(b&1)res=res*a%m;a=a*a%m;}return res;}
ll numdigit(ll n){return floor(log10(n)) + 1;}
bool isPowerTwo (ll x) { return x && (!(x&(x-1))); }
ll dp[200005]; 
vector<ll>grp[200005];
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		zero(dp);
		for(ll i=1;i<=k;i++){
			for(ll j=2*i;j<=k;j+=i){
				grp[i].pb(j);
			}
		}
		for(int i=1;i<=k;i++){
			ll num=k/i;
			dp[i]=modpow(num,n,MOD);
			// cout<<"i= "<<i<<" dp= "<<dp[i]<<endl;
		}
		for(ll i=k;i>=1;i--){
			for(ll j=0;j<grp[i].size();j++){
				ll m=grp[i][j];
				// cout<<i<<" "<<grp[i][j]<<endl;
				dp[i]=(dp[i]-dp[m]+MOD)%MOD;
			}
		}
		ll res=0;
		// cout<<"After DP"<<endl;
		for(ll i=1;i<=k;i++){
			// cout<<i<<" "<<dp[i]<<endl;
			res=(res+(dp[i]*i)%MOD)%MOD;
			// cout<<"i= "<<i<<" dp = "<<dp[i]<<endl;
		}
		cout<<res<<endl;
	}	
}
