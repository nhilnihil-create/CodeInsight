#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<long long,long long>
#define ii pair<ll,ll>
#define mod 1000000007
#define endl '\n'
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);

ll power(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2!=0){
			ans=(ans*a)%mod;
		}
		a=((a%mod)*(a%mod))%mod;
		b>>=1;
	}
	return ans;
}

void sieve(ll n){
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	for(ll p=2;p*p<=n;p++){
		if(prime[p]){
			for(ll i=p*p;i<=n;i+=p)
				prime[i]=false;
		}
	}
	for(ll p=2;p<=n;p++){
		if(prime[p])
			cout<<p<<" ";
	}
}


int main() {
	IOS;
	ll t=1;
	//cin>>t;
	while(t--){
		string s,t;
		cin>>s>>t;
		vector<ll> v[26];
		for(ll i=0;i<s.size();i++){
			v[s[i]-'a'].push_back(i);
		}
		ll cnt=0;
		ll j=-1;
		for(ll i=0;i<t.size();i++){
			if(v[t[i]-'a'].size()==0){
				cout<<-1;
				return 0;
			}
			ll kha=t[i]-'a';
			ll ind=upper_bound(v[kha].begin(),v[kha].end(),j)-v[kha].begin();
			if(ind==v[kha].size()){
				j=v[kha][0];
				cnt++;
			}
			else{
				j=v[kha][ind];
			}
		}
		cout<<cnt*s.size()+j+1;
	}
	return 0;
}