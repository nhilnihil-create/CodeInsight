#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

ll mod_pow(ll x, ll n)
{
    if (n == 0)
        return 1;
    ll fact = x;
    ll out = 1;
    while (n > 0) {
        if (n & 1) {
            out = out * fact % MOD;
        }
        fact = fact * fact % MOD;
        n >>= 1;
    }
    return out;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    map<ll, ll> d;

    for (ll gcd = k; gcd >= 1; gcd--) {
        d[gcd] = mod_pow(k / gcd, n);
        for (ll i = 2; gcd * i <= k; i++) {
            d[gcd] = (d[gcd] - d[gcd * i]) % MOD;
        }
    }

    ll ans = 0;
    for (ll i = 1; i <= k; i++) {
        ans = (ans + d[i] * i % MOD) % MOD;
    }

    cout << ans << endl;
}