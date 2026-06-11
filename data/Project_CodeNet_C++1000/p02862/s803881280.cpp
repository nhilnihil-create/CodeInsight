#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>
typedef long long ll;
using namespace std;
const int mod=1e9+7;
const ll inf=(1e14);

int extended_euclidean(int a,int b,ll &x,ll &y){
	if(!b){
		x=1;y=0;
		return a;
	}
	ll x1,y1;
	int g=extended_euclidean(b,a%b,x1,y1);
	x = y1;
	y = x1 - y1*(a/b);
	return g;
}

ll c(ll n,ll r){
	ll nf=1;
	for(ll i=2;i<=n;i++) nf=(nf*i)%mod;
	ll rf=1,nrf=1;
	for(ll i=2;i<=r;i++) rf=(rf*i)%mod;
	for(ll i=2;i<=n-r;i++) nrf=(nrf*i)%mod;
	ll rfi,nrfi,t;
	extended_euclidean(mod,rf,t,rfi);
	extended_euclidean(mod,nrf,t,nrfi);
	rfi%=mod;nrfi%=mod;
	rfi=(rfi+mod)%mod;
	nrfi=(nrfi+mod)%mod;
	return (((nf*rfi)%mod)*nrfi)%mod;
}

ll solve(){
	int x,y;
	cin>>x>>y;
	int a = (2*x-y)/3, b = (2*y-x)/3;
	if( (a<0) || (b<0) || (2*a+b != x) || (2*b+a != y) ) return 0;
	return c(a+b,a);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    while(t--) cout<<solve()<<'\n';
    //while(t--) solve(),cout<<'\n';
    return 0;
}
