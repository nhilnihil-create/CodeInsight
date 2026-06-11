// 問題の URL を書いておく
// https://atcoder.jp/contests/abc166/tasks/abc166_d

#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;

//#define ENABLE_PRINT

#if defined(ENABLE_PRINT)

#define Print(v) \
do {\
    cout << #v << ": " << v << endl; \
}while(0)

#define PrintVec(v) \
do {\
    for(int __i = 0; __i < v.size(); ++__i) \
    { \
        cout << #v << "[" << __i << "]: " << v[__i] << endl; \
    }\
}while(0)

#else

#define Print(v) ((void)0)
#define PrintVec(v) ((void)0)

#endif

#define rep(i, n) for(int i = 0; i < (int)(n); ++i)

using ll = int64_t;

ll pow5(ll x)
{
    auto t = x * x;
    return t * t * x;
}

map<ll, ll> d;

int main(int, const char**)
{
    ll x;
    cin >> x;
    ll prev = 0;
    ll i = 0;
    while(true)
    {
        auto x = pow5(i);
        d[x] = i;
//        cout << x - prev << endl;
        if(x - prev > 1000000000)
        {
            break;
        }
        i++;
        prev = x;
        d[pow5(-i)] = -i;
    }

    ll a = 0, b = 0;
    for(auto p : d)
    {
        auto diff = p.first - x;
        if(d.find(diff) != d.end())
        {
            a = p.second;
            b = d[diff];
            break;
        }
    }

    cout << a << " " << b << endl;

    return 0;
}
