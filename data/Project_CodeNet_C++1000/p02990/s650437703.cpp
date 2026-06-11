#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define  point complex<double>
#define  pi acos(-1)
#define  ll long long
const ll mod=1e9+7 ;
const ll N=2e5+5;

        double dot (point a,point b){
            return  (conj(a)*b).real();
        }
        double cross(point a,point b){
            return  (conj(a)*b).imag();
        }
double angle(point a, point b)
{
    double dt = dot(a, b);
    dt /= abs(a);
    dt /= abs(b);
    return acos(dt) * 180.0 / pi;
}
ll d, x, y;
void extendedEuclid(ll A, ll B) {
    if (B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        int temp = x;
        x = y;
        y = temp - (A / B)*y;
    }
}
ll modInverse(ll A, ll M)
{
    extendedEuclid(A, M);
    return (x%M + M) % M;
}
ll fact[1000006], inv[1000006];

ll fp(ll base, ll exp)
{
    if (exp == 0)
        return 1;
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
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

ll npr(ll n, ll r)
{
    return (fact[n] * inv[n - r]) % mod;
}

int main() {
ll n,k;
cin >>n>>k;
calcFacAndInv(1000000);
for (ll i=1;i<=k;++i) {
if (n-k+1<i){
    cout <<0<<endl;
}
else
    cout <<( ncr(n-k+1,i)*ncr(k-1,i-1))%mod<<endl;
}
    return 0;
}
