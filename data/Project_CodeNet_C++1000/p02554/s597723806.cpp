#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;

ll power(ll x, ll N){
	ll res = 1;
  
	for(ll i=1; i<=N; i++)
    {
		res*=x;
		res%=mod;
	}
  
	return res;
}


int main(){
	ll N;
	cin>>N;

	ll total = power(10, N);
	ll noZero = power(9, N);
	ll noNine = power(9, N);
	ll neitherZeroNorNine = power(8, N);

	ll ans = total - noNine - noZero + neitherZeroNorNine;
	ans%=mod;
	ans = (ans+mod)%mod;
	cout<<ans;

	return 0;
}
