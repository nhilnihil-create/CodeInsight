//By Zank100
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod 1000000007
#define din(t) long long t;cin>>t;
#define in(t) cin>>t;
ll mul(ll a, ll b)
{
    return(((a%mod)*(b%mod))%mod);
}
ll modexp(ll b, ll e){
	ll res = 1;
	for(; e; b = b * b % mod, e >>= 1) if(e & 1) res = res * b % mod;
	return res;
}
ll modinv(ll a){
    ll x=mod-2;
	return modexp(a,x);
}
ll power(ll x, ll y)
{
    ll temp;
    if(y == 0)return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)return temp*temp;
    else{
        if(y > 0)return x * temp * temp;
        else return (temp * temp) / x;
    }
}
ll cc(ll x,ll y){
    if(x-y>0)return 1;
    else if(x-y<0)return -1;
    else return 0;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	din(h1)din(m1)din(h2)din(m2)din(k)
	ll total=(h2*60 + m2)-(h1*60 + m1);
	ll ans=total - k;
	cout<<ans<<endl;

	return 0;
}
