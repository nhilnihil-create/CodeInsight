// 問題の URL を書いておく
// 

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

ll solve(ll x, ll k, ll d)
{
    x = abs(x);

    auto dc = min(k, x / d);
    auto rest = x - dc * d;
    auto restK = k - dc;
    if(restK % 2 == 0)
    {
        return rest;
    }
    else
    {
        return d - rest;
    }
    abort();
}

int main(int, const char**)
{
    ll x, k, d;
    cin >> x >> k >> d;

    auto ans0 = solve(x, k, d);
    cout << ans0 << endl;
}
