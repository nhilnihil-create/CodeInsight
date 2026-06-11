
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

template <class T>
using vec = vector<T>;
template <class T>
using vec2 = vector<vector<T>>;

constexpr int INF = numeric_limits<int>::max();
constexpr ll INFL = numeric_limits<ll>::max();
constexpr ll MOD = 1000000007; // 10^9+7

#define rep(i, n) for (ll i = 0, i##_len = (n); i < i##_len; ++i)

int main()
{
    int n;
    ll d;
    cin >> n >> d;
    int ret = 0;
    rep(i, n)
    {
        ll x, y;
        cin >> x >> y;
        if (d * d >= x * x + y * y)
        {
            ret++;
        }
    }

    cout << ret << endl;

    return 0;
}
