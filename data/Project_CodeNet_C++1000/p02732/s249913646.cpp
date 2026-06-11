#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll p(ll a,ll b){
	ll sum=1,cnt=0;
	for(ll i=a;cnt<b;i--){
		sum*=i;
		cnt++;
	}
	return sum;
}

ll c(ll a,ll b){
	ll r=1;
	for(ll i=1;i<=b;i++){
		r*=i;
	}
	return a/r;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	map<ll,ll>mp;
	ll n,a;
	cin>>n;
	vector<ll>v(200001);
	for(ll i=0;i<n;i++){
		cin>>a;
		mp[a]++;
		v[i]=a;
	}
	vector<ll>vv(200001);
	for(auto p:mp){
		auto a=p.first;
		auto b=p.second;
		vv[a]=b;
	}
	ll sum=0;
	vector<ll>vvv(200001);
	for(ll i=0;i<200001;i++){
		vvv[v[i]]=c(p(mp[v[i]],2),2);
		if(vv[i]==0)continue;
		sum+=c(p(mp[i],2),2);
	}
	for(ll i=0;i<n;i++){
		cout<<sum-vvv[v[i]]+c(p(mp[v[i]]-1,2),2)<<endl;
	}
	return 0;
}

