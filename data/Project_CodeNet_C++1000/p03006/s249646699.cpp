#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x[55],y[55];
int main(){
	ll n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>x[i]>>y[i];
	map<pair<ll,ll>,ll>mp;
	ll ma=0;
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
		mp[make_pair(x[i]-x[j],y[i]-y[j])]++;
		mp[make_pair(x[j]-x[i],y[j]-y[i])]++;
		ma=max(ma,mp[make_pair(x[i]-x[j],y[i]-y[j])]);
		ma=max(ma,mp[make_pair(x[j]-x[i],y[j]-y[i])]);
	}
	cout<<n-ma<<endl;
	return 0;
}
