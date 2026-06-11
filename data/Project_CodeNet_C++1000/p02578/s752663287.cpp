#include<bits/stdc++.h>
#define ll long long
#define mod (long long)(1e9+7)
#define endl "\n"
using namespace std;


void solve(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	stack<ll> st;
	ll prev[n];
	ll ans=0;
	ll maxi=LLONG_MIN;
	for(ll i=0;i<n;i++){
		maxi=max(maxi,a[i]);
		ans+=(maxi-a[i]);
	}
	cout<<ans<<endl;
}


int main(){
	ll t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}
