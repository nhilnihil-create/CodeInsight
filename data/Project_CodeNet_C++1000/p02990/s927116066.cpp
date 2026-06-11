#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007
#define point complex<double>

typedef long long ll;

using namespace std;

void Fastio(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
double pi=acos(-1);

double adotb(point a, point b){
    return (conj(a)*b).real();
}

double acrossb(point a, point b){
    return (conj(a)*b).imag();
}

double sinseta(point a, point b){
    double res=asin(abs(acrossb(a,b)/(abs(a)*abs(b))))*180.0/pi;
    if(res>180.0)res-=180.0;
    return res;
}

ll fact[1000006], inv[1000006];

ll fp(ll base, ll exp)
{
    if (exp == 0)
        return 1;
    if (exp == 1)
        return base;
    ll ans = fp(base, exp / 2);
    ans = (ans * ans) % mod;
    if (exp % 2 != 0)
        ans = (ans * (base % mod)) % mod;
    return ans;
}

void calcFacAndInv(ll n)
{
    fact[0] = inv[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = fp(fact[i], mod - 2);
    }
}

ll ncr(ll n, ll r)
{
    if(n<r)return 0;
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

ll npr(ll n, ll r)
{
    return (fact[n] * inv[n - r]) % mod;
}

int main()
{
    Fastio();
    calcFacAndInv(1e5);
    ll n,k; cin>>n>>k;
    for(int i=1; i<=k; i++){
        ll ans=ncr(n-k+1,i)* ncr(k-1,i-1);
        cout<<ans%mod<<'\n';
    }

    return 0;
}
