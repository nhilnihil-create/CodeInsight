#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1000000007;

ll x, y;

ll extended_gcd(ll a, ll b){
	if(b==0){
		x = 1;
		y = 0;
		//printf("%lld*%lld + %lld*%lld = %lld\n", a, x, b, y, a); 
		return a;
	}
	else{
		ll g = extended_gcd(b, a%b);
		/*
			b*x + y*(a - a/b*b) = g
			a*y + b*(x - a/b*y) = g
		*/
		ll tmp = x;
		x = y;
		y = tmp-a/b*y;
		//printf("%lld*%lld + %lld*%lld = %lld\n", a, x, b, y, g);
		return g;
	}
}

ll modinverse(ll a){
	ll g = extended_gcd(a, mod);
	//cout<<g<<"\n";
	while(x<0)
		x+=mod;
	return x;
}

ull nCr(ll n, ll r){
	ull prod = 1;
	for(int i=n-r+1;i<=n;i++)
		prod = (prod*i)%mod;
	for(int i=1;i<=r;i++)
		prod = (prod*modinverse(i))%mod;
	//cout<<prod<<"\n";
	return prod;
}

ull powx(ll b, ll exp){
	if(exp == 0)
		return 1;
	else{
		ull ans = powx(b, exp/2);
		ans = (ans*ans)%mod;
		if(exp%2)
			ans = (ans*b)%mod;
		return ans;
	}
}

int main(){
	ll n, a, b;
	cin>>n>>a>>b;
	ll ans = powx(2, n)-1;
	ans = (ans-nCr(n, a));
	while(ans<0)
		ans+=mod;
	ans = (ans-nCr(n, b));
	while(ans<0)
		ans+=mod;
	ans = ans%mod;	
	cout<<ans<<"\n";
	return 0;
}