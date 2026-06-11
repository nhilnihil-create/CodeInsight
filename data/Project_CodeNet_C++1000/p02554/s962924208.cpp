#include <bits/stdc++.h>
#define ll long long
#define mod (ll)(1e9 + 7)
using namespace std;

ll sub(ll a, ll b){
	ll r = (a - b)%mod;
	r += mod;
	r %= mod;
	return r;
}

ll add(ll a, ll b){
	return (a + b)%mod;
}

ll mul(ll a, ll b){
	return a * b % mod;
}

ll my_pow(ll a, ll b){
	// a^b
	ll res = 1LL;
	while(b){
		if(b&1) res = mul(res,a);
		a = mul(a,a);
		b = b / 2;
	}
	return res;
}

int main() {
	// your code goes here
	ll n;
	cin>>n;
	ll a = add(my_pow(10,n),my_pow(8,n));
	ll b = mul(2,my_pow(9,n));
	ll ans = sub(a,b);
	cout<<ans<<"\n";
	return 0;
}