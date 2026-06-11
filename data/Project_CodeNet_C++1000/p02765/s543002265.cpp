
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

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)

int main()
{
    int n, r;
    cin >> n >> r;

    if (n >= 10)
        cout << r << endl;
    else
        cout << r + 100 * (10 - n) << endl;

    return 0;
}
