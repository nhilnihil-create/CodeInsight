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
    ll c[10][10] = {};
    rep(i, n)
    {
        auto k = i + 1;
        auto t = k % 10;
        auto h = k / (int)pow(10, (int)log10(k));
        c[h][t]++;
    }

    ll ans = 0;
    rep(i, 9)
    {
        rep(j, 9)
        {
            auto d = c[i + 1][j + 1] * c[j + 1][i + 1];
            ans += d;
        }
    }
    cout << ans << endl;

    return 0;
}
