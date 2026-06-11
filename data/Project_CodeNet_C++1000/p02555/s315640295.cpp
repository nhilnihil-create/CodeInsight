#include <bits/stdc++.h>

using namespace std;

#define ll  long long
#define f first
#define s second

const int N = 1e5+5;

ll mod = 1e9+7;
ll fact[N] , inv[N];

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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    calcFacAndInv(N-2);
    ll sum , ans=0;
    cin >> sum;

    for(int i=1; i<=sum; i++) //size of seq
    {
        ll rem = sum - i*3;
        if (rem < 0) break;
        ans = (ans+ncr(i+rem-1 , rem))%mod;
    }

    cout << ans << '\n';

    return 0;
}