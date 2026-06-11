#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[2020],a[2020],cnt2[2020];
int main(){
	ll n,k,mod=1e9+7;
	cin>>n>>k;
	ll ans=0;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		if(a[i]>a[j])cnt[i]++;
		if(i<j&&a[i]>a[j])cnt2[i]++;
	}
	ll x=k*(k-1)/2;
	x%=mod;
	for(int i=0;i<n;i++){
		ans+=x*cnt[i];
		ans%=mod;
		ll num=k*cnt2[i];
		num%=mod;
		ans+=num;
		ans%=mod;
	}
	cout<<ans;
	return 0;
}
