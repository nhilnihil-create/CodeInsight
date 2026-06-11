#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,ll> mp;
ll a[300005];
int main()
{
	ll n;cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	ll ans=0;
	for(map<ll,ll>::iterator it=mp.begin();it!=mp.end();it++){
		if(it->second<2)continue;
		ans+=it->second*(it->second-1)/2;
	}
	for(int i=1;i<=n;i++){
		
		printf("%lld\n",ans-(mp[a[i]]-1));
	}
}