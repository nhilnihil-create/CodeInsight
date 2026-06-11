#include<bits/stdc++.h>
#include <iostream>
#include <numeric>
#include <math.h>
#define ll  long long
#define ull unsigned long
#define mpa make_pair
#define pb push_back
#define ff first
#define pii pair<ll,ll>
#define dd double
#define trace(x) cerr << #x << " : " << x << endl
#define ss second
#define boost ios_base::sync_with_stdio(0)
#define forp(i,a,b) for(ll i=a;i<=b;i++)
#define rep(i,n)    for(ll i=0;i<n;++i)
#define ren(i,n)    for(ll i=n-1;i>=0;i--)
#define forn(i,a,b) for(ll i=a;i>=b;i--)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end();
#define sc(x) scanf("%lld",&x)
#define clr(x,val) memset(x,val,sizeof(x))
#define pr(x) printf("%lld\n",x) 
#define gc getchar
#define pdd pair<dd,dd>
#define prec(x) cout<<fixed<<setprecision(x)
using namespace std;
ll a[200005];
ll b[100005];
ll modpow(ll a,ll n,ll tmp){
	ll res=1ll;
	while(n){
		if(n%2)res=(res*a)%tmp;
		a=(a*a)%tmp;
		n/=2ll;
	}
	return res;
}
bool cmp(ll a,ll b){
	return abs(a)>abs(b);
}
int main(){
    ll n,k;
    boost;
    cin>>n;
    ll ans=n*(n+1)*(n+2);
    ans/=6ll;
    for(ll i=1;i<n;i++){
    	ll u,v;
    	cin>>u>>v;
    	if(u>v)swap(u,v);
    	ans-=(u*(n-v+1ll));
	}
	cout<<ans;
			
			
			
}