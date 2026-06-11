#include <iostream>
using namespace std;

#define mod 1000000007
typedef long long ll;

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

void facninv(ll n)
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

int main()
{  int n,k;
    ll ans;
   facninv(2001);
   cin>>n>>k;
   int r=n-k;
   for(int i=1;i<=k;i++){
    if(r+1>=i)
    ans=(ncr(r+1,i)*ncr(k-1,i-1))%mod;
    else ans=0;
   cout<<ans<<endl;
   }

    return 0;
}
