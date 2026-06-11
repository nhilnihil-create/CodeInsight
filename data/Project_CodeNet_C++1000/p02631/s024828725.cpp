#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
	ios_base::sync_with_stdio(false);

	ll n;
	cin>>n;
	ll a[n+1];
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	ll last=a[1];
	for(ll i=3;i<n;i+=2){
		ll now=a[i]^a[i-1];
		last=last^now;
	}
	ll ans[n+1];
	ans[n]=last;
	for(ll i=n-1;i>0;i--){
		ll now=a[i+1]^a[i];
		now=now^ans[i+1];
		ans[i]=now;
	}
	for(ll i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}