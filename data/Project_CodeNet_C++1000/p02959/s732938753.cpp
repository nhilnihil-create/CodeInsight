#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
int main(){
	ll n; cin>>n;
	ll m[n+1]; for(ll i=0;i<=n;i++) cin>>m[i];
	ll h[n]; for(ll i=0;i<n;i++) cin>>h[i];
	ll ans=0;
	for(ll i=0;i<n;i++){
		ll x=min(m[i],h[i]);
		h[i]-=x;
		m[i]-=x;
		ans+=x;
		x=min(m[i+1],h[i]);
		h[i]-=x;
		m[i+1]-=x;
		ans+=x;
	}
	cout<<ans;
}