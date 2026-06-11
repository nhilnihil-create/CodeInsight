#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define pb push_back
#define mp make_pair
#define ub(v,val) upper_bound(v.begin(),v.end(),val)-v.begin()
#define lb(v,val) lower_bound(v.begin(),v.end(),val)-v.begin()
#define sortv(vec) sort(vec.begin(),vec.end())
#define v vector
#define PI 3.1415926535
#define len length()
#define repc(i,s,e) for(ll i=s;i<e;i++)
#define fi first
#define se second
#define mt make_tuple
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define rep(i,n) for(ll i=0;i<n;i++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
const int M = 1e9+7;
int ll_max=1e6;
v<ll> fact;
//factorial
void factorial(ll n)
{
    fact[0] = 1;
    for (ll i = 1; i <=n; i++)
    {
        fact[i] = i * fact[i - 1];
        fact[i] %= M;
    }
}
// modular exponentiation 
ll binpow(ll val, ll deg)
{
    if (!deg)
        return 1 % M;
    if (deg & 1)
        return binpow(val, deg - 1) * val % M;
    ll res = binpow(val, deg >> 1);
    return (res * res) % M;
}
//combination
ll C(ll n, ll i)
{
    if(n<i) return 0;      
    ll res = fact[n]; 
    ll div = fact[n - i] * fact[i];
    div %= M;
    // using fermat little theorum
    div = binpow(div, M - 2); // modular inverse  
    return (res * div) % M; 
}
int main() {
	//your code goes here
	IOS;
	ll n,m;       
	ll j,y,z,k,b,a,x,t,i;   
	 cin>>n;
	 ll V=0;
	 for(i=1;i<=n;i++){
	       V+=i*(n+1-i);
	 }
	 ll edges=0;
	 rep(i,n-1){
	       ll u,v;
	       cin>>u>>v;
	       ll mn=min(u,v);
	       ll mx=max(u,v);
	       edges+=mn*(n+1-mx);
	 }
	 cout<<V-edges;
	 
	return 0;
}