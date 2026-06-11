#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 1000000007;

ll inv(ll n){
	if(n == 1)return 1;
	return inv(mod%n)*(mod - mod/n)%mod;
}

ll modPow(ll a, ll b){
	ll ret = 1;
	while(b){
		if(b&1)(ret *= a) %= mod;
		(a *= a) %= mod;
		b >>= 1;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n, a, b;
	cin>>n>>a>>b;
	ll tot = modPow(2, n) - 1;
	{
		ll num = 1, den = 1;
		for(int i = 1; i <= a; i++){
			(num *= (n - i + 1)) %= mod;
			(den *= i) %= mod;
		}
		tot += mod - (num*inv(den)%mod);
	}
	{
		ll num = 1, den = 1;
		for(int i = 1; i <= b; i++){
			(num *= (n - i + 1)) %= mod;
			(den *= i) %= mod;
		}
		tot += mod - (num*inv(den)%mod);
	}
	tot %= mod;
	cout<<tot<<endl;

	return 0;
}