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
    ll n;
    cin >> n;
    map<ll, ll> counts;
    for(ll i = 2; i * i <= n; ++i)
    {
        while(n % i == 0)
        {
            if(counts.find(i) == counts.end())
            {
                counts[i] = 0;
            }
            counts[i]++;
            n /= i;
        }
    }
    if(n != 1)
    {
        counts[n] = 1;
    }
    ll ans = 0;
    for(auto c : counts)
    {
        ll b = 1;
        ll rest = c.second;
        while(b <= rest)
        {
            rest -= b;
            b++;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
