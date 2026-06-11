
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

ll N;
string C;

ll solve()
{
    int l = 0;
    int r = N - 1;
    ll ret = 0;
    while (r > l)
    {
        if (C[l] == 'R')
        {
            ++l;
        }
        else if (C[r] == 'W')
        {
            --r;
        }
        else
        {
            --r;
            ++l;
            ++ret;
        }
    }

    return ret;
}

int main()
{
    cin >> N >> C;
    cout << solve() << endl;
    return 0;
}
