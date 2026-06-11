#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <cctype>
#include <bitset>
#include <type_traits>

#include <list>
using namespace std;

#define REP(i, n) for (long long i = 0; i < (n); ++i)
#define rep(i, a, b) for (long long i = a; i < (b); ++i)
#define YES(j) cout << (j ? "YES" : "NO") << endl;
#define Yes(j) std::cout << (j ? "Yes" : "No") << endl;

typedef long long ll;
const ll MOD = 1'000'000'007;
ll mod_powe(ll x, ll n, ll mod)
{
    ll res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
int main(void)
{
    ll n, k;
    ll ans = 0;

    cin >> n >> k;

    map<ll, ll> mp;
    // gcd が 1 ~ k のものを全部合算する
    // gcdがkのもの (k / i) ^ n 個存在する
    for (ll i = k; i >= 1; i--)
    {
        ll tmp = 1;
        /*
        REP(j, n)
        {
            tmp = (tmp * (k / i)) % MOD;
        }
        */
        tmp = mod_powe(k / i, n, MOD);

        // x
        mp[i] = tmp;
        // - 2x - 3x ...
        for (ll j = i * 2; j <= k; j += i)
        {
            if (mp.count(j) > 0)
            {
                mp[i] = (mp[i] + MOD - mp[j]) % MOD;
            }
        }

        ans = (ans + mp[i] * i) % MOD;
    }

    cout << ans << endl;
}