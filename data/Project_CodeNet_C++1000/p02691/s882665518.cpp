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

int main(int, const char**)
{
    int n;
    cin >> n;
    map<ll, ll> c0, c1;
    set<ll> vs;
    rep(i, n)
    {
        auto num = i + 1;
        ll a;
        cin >> a;
        auto v0 = num + a;
        if(c0.find(v0) == c0.end())
        {
            c0[v0] = 0;
        }
        c0[v0]++;
        vs.insert(v0);

        auto v1 = num - a;
        if(c1.find(v1) == c1.end())
        {
            c1[v1] = 0;
        }
        c1[v1]++;
        vs.insert(v1);
    }

    ll ans = 0;
    for(auto v : vs)
    {
        ans += c0[v] * c1[v];
    }

    cout << ans << endl;

    return 0;
}
