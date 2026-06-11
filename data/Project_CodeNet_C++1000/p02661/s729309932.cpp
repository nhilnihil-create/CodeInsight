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
    vector<ll> a(n), b(n);
    rep(i, n)
    {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    auto calcMedian = [](vector<ll>& v) -> ll
    {
        sort(v.begin(), v.end());
        auto s = v.size();
        if(s % 2 == 0)
        {
            return v[s / 2 - 1] + v[s / 2];
        }
        return v[s / 2];
    };

    auto mMin = calcMedian(a);
    auto mMax = calcMedian(b);
    cout << mMax - mMin + 1 << endl;

    return 0;
}
