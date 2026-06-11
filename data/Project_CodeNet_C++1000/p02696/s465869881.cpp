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

using ll = uint64_t;

int main(int, const char**)
{
    ll a, b, n;
    cin >> a >> b >> n;
#if 0
    for(ll i = 0; i < n; ++i)
    {
        auto v = (a * i / b) - (a * (i / b));
        printf("x: %ld, v: %ld\n", i, v);
    }
#endif
    auto x = min(b - 1, n);
    auto v = (a * x / b) - (a * (x / b));
    cout << v << endl;
    return 0;
}
