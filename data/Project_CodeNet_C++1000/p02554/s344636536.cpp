#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
using ll=long long;

ll modpow(ll n,ll m=mod-2){
  ll r=1;
  while(m){
    r=r*((m%2)?n:1)%mod,n=n*n%mod,m>>=1;
  }
  return r;
}

int main(){
	
	int n;
	cin >> n;

	ll ans = modpow(10,n);
	ans=ans+modpow(8,n);
	ans=ans%mod;
	ans=ans-modpow(9,n);
	ans=ans%mod;
	ans=ans-modpow(9,n);
	ans=ans%mod;

	ans=(ans+mod)%mod;
	cout << ans << endl;
}
