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
    vector<ll> l(n);
    rep(i, n)
    {
        cin >> l[i];
    }

    int ans = 0;
    for(int i = 0; i < n - 2; ++i)
    {
        for(int j = i + 1; j < n - 1; ++j)
        {
            for(int k = j + 1; k < n; ++k)
            {
                auto a = l[i];
                auto b = l[j];
                auto c = l[k];
                if(a == b || a == c || b == c)
                {
                    continue;
                }
                if(a + b > c && a + c > b && b + c > a)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
