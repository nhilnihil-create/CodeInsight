#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define mod 1000000007
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

ll power(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2!=0){
			ans=(ans*a)%mod;
		}
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}
ll check(ll a[],ll m,ll n){
	ll b[n];
	for(int i=0;i<n;i++){
		b[i]=a[i]%m;
	}
	sort(b,b+n);
	ll cnt=0;
	int i=0,j=n-1;
	while(i<j){
		if(b[i]==0){
			i++;
			continue;
		}
		if(b[j]==0){
			j--;
			continue;
		}
		int lo=min(b[i],m-b[j]);
		cnt+=lo;
		b[i]-=lo;
		b[j]+=lo;
		b[i]%=m;
		b[j]%=m;
	}
	for(int i=0;i<n;i++){
		if(b[i]!=0)
		return 1e18;
	}
	return cnt;
}

int main() {
	IOS;
	int t=1;
	//cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		ll s=0;
		ll a[n];
		for(ll i=0;i<n;i++){
			cin>>a[i];
			s+=a[i];
		}
		vector<ll> v;
		for(ll i=1;i*i<=s;i++){
			if(s%i!=0)
			continue;
			v.push_back(i);
			if(i*i!=s)
			v.push_back(s/i);
		}
		sort(v.begin(),v.end(),greater<ll>());
		for(int i=0;i<v.size();i++){
			ll z=check(a,v[i],n);
			if(z<=k){
				cout<<v[i];
				return 0;
			}
		}
	}
	return 0;
}