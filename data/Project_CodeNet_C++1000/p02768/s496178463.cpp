#include <iostream>
#include <iomanip>
#include <vector>
typedef long long ll;
using namespace std;
const ll INF = 1e9;
const ll MOD = 1e9 + 7;
#define repi(i, n, init) for (ll i = init; i < (n); i++)
vector<ll> fact, invfact;
ll modpow(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
        {
            res = res * a % MOD;
        }
        a = a * a % MOD;
        n /= 2;
    }
    return res;
}

ll modinv(ll a)
{
    return modpow(a, MOD - 2);
}

ll nCk(ll n, ll k)
{
    ll inv = 1;
    ll fact = 1;
    repi(i,k,0){
        fact *= (n-i);
        fact %= MOD;
    }
    repi(i, k + 1, 1)
    {
        inv *= modinv(i);
        inv %= MOD;
    }
    return fact * inv % MOD;
}
int main()
{
    ll n, a, b;
    cin >> n >> a >> b;
    ll bin = modpow(2,n);
    ll ans = (bin - 1 - nCk(n, a) - nCk(n, b)) % MOD;
    if(ans < 0)ans += MOD;
    cout << ans << endl;
    return 0;
}