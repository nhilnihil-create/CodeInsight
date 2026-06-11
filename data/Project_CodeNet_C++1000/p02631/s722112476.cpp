#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[214514],cnt[35];
ll ans[214514];
int main(){
	ll n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<32;j++){
			ll x=(1ll<<j);
			if(x&a[i])cnt[j]++;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<32;j++){
			ll x=(1ll<<j);
			if(cnt[j]%2){
				ans[i]+=(a[i]&x)^x;
			}
			else ans[i]+=(a[i]&x);
		}
		cout<<ans[i]<<' ';
	}
	return 0;
}
