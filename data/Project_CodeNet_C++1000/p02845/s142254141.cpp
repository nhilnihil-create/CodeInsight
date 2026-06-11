#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ll n;
	cin>>n;
	ll ans=1,mod=1e9+7;
	ll cnt[3]={};
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		ll num=0;
		for(int j=0;j<3;j++)if(cnt[j]==x)num++;
		for(int j=0;j<3;j++){
			if(cnt[j]==x){
				cnt[j]++;
				break;
			}
		}
		ans*=num;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
