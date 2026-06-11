
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

template <class T>
using vec = vector<T>;
template <class T>
using vec2 = vector<vec<T>>;
template <class T>
using vec3 = vector<vec2<T>>;

constexpr int INF = numeric_limits<int>::max();
constexpr ll INFL = numeric_limits<ll>::max();
constexpr ll MOD = 1000000007; // 10^9+7

#define rep(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)

constexpr ll solve(ll k)
{
    if (k % 2 == 0 || k % 5 == 0)
    {
        return -1;
    }

    ll n = 0;
    ll ret = 0;
    while (ret == 0 || n != 0)
    {
        n = n * 10 + 7;
        n %= k;
        ret++;
    }
    return ret;
}

int main()
{
    ll k = 0;
    cin >> k;
    cout << solve(k) << endl;
    return 0;
}
