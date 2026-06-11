#include <bits/stdc++.h>
#define endl '\n'
#define f first
#define s second
#define point complex<double>
#define pi acos(-1)
#define ld long double
using namespace std;
typedef long long ll;
const int xd=1e6;
const ll mod=1e9+7;
double dot(point a,point b)
{
    return (conj(a)*b).real();
}
double cross(point a,point b)
{
    return (conj(a)*b).imag();
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
calcFacAndInv(10000);
int n,b,r;
ll ansb,ansa;
cin>>n>>b;
r=n-b;
for(int i=1;i<=b;i++){
        if(r+1<i){
            cout<<0<<endl;
            continue;
        }
ansb=ncr(b-1,i-1)%mod;
ansa=ncr(r+1,i)%mod;
cout<<(ansb*ansa)%mod<<endl;;
}

    return 0;
}
