#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define watch(x) cout<<(#x)<<"="<<(x)<<'\n'
#define mset(d,val) memset(d,val,sizeof(d))
#define setp(x) cout<<fixed<<setprecision(x)
#define forn(i,a,b) for(int i=(a);i<(b);i++)
#define fore(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define F first
#define S second
#define pqueue priority_queue
#define fbo find_by_order
#define ook order_of_key
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
void amin(ll &a, ll b){ a=min(a,b); }
void amax(ll &a, ll b){ a=max(a,b); }
void SD(int t=0){ cout<<"PASSED "<<t<<endl; }
const ll INF = ll(1e18);
const int MOD = 1e9+7;

const int MAXN = 100005;

ll add(ll a,ll b)
{
	a%=MOD; b%=MOD;
	a+=b;a%=MOD;
	if(a<0) a+=MOD;
	return a;
}
ll mult(ll a, ll b)
{
	a%=MOD; b%=MOD;
	ll ans=(a*b)%MOD;
	if(ans<0) ans+=MOD;
	return ans;
}
ll pw(ll a, ll b)
{
	ll r=1;
	while(b){
		if(b&1) r=mult(r,a);
		a=mult(a,a);
		b>>=1;
	}
	return r;
}
ll add2(ll a,ll b)
{
	a%=13; b%=13;
	a+=b;a%=13;
	if(a<0) a+=13;
	return a;
}
ll mult2(ll a, ll b)
{
	a%=13; b%=13;
	ll ans=(a*b)%13;
	if(ans<0) ans+=13;
	return ans;
}
ll pw2(ll a, ll b)
{
	ll r=1;
	while(b){
		if(b&1) r=mult2(r,a);
		a=mult2(a,a);
		b>>=1;
	}
	return r;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	string s; cin>>s; s='0'+s;
	int n=s.length();
	
	ll dp[n][13]{};
	dp[0][0]=1;
	
	forn(i,1,n){
		forn(j,0,13){
			forn(k,0,10){
				if(s[i]!='?' && s[i]-'0'!=k) continue;
				dp[i][j]=add(dp[i][j], dp[i-1][add2(j,-mult2(k, pw2(10,n-1-i)))]);
			}
		}
	}
	
	cout<<dp[n-1][5]<<'\n';
	
	return 0;
}
