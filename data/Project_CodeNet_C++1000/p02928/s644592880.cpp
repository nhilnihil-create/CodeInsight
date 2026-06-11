#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2001],ans,p[2001],mod=1000000007;
int main(){
	ll n,k;
	cin>>n>>k;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			if(a[j]<a[i]){
				ans=ans+k;
				ans%=mod;
			}
		}
		for(ll j=1;j<=n;j++){
			if(a[j]<a[i]){
				ans=ans+k*(k-1)/2;
				ans%=mod;
			}
		}
	}
	cout<<ans;
	return 0;
}