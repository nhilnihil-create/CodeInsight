#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pll pair<ll,ll> 

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n,d;
	cin>>n>>d;
	ll ans=0;
	for(ll i=0;i<n;i++){
		ll x, y;
		cin>>x>>y;
		if(x*x+y*y<=d*d)
			ans++;
	}
	cout<<ans<<endl;
}
