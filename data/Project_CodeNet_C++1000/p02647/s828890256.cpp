#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll a[214514];
int main(){
	ll n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	while(k--){
		ll cnt=0;
		ll b[214514]={};
		for(ll i=0;i<n;i++){
			ll l=max(0ll,i-a[i]),r=min(n-1,i+a[i]);
			b[l]++;
			b[r+1]--;
			//cout<<l<<' '<<r<<endl;
		}
		for(int i=1;i<n;i++){
			b[i]+=b[i-1];
			if(b[i]==n)cnt++;
		}
		if(b[0]==n)cnt++;
		for(int i=0;i<n;i++)a[i]=b[i];

		if(cnt==n)break;
	}
	for(int i=0;i<n;i++)cout<<a[i]<<' ';
	return 0;
}