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
    string s;
    cin >> s;
    vector<int> r(n), g(n), b(n);
    r.resize(0); g.resize(0); b.resize(0);
    rep(i, n)
    {
        auto c = s[i];
        if(c == 'R')
        {
            r.push_back(i);
        }
        else if(c == 'G')
        {
            g.push_back(i);
        }
        else
        {
            b.push_back(i);
        }
    }
    ll ans = 0;
    for(auto ri : r)
    {
        for(auto gi : g)
        {
            auto h = max(ri, gi);
            auto l = min(ri, gi);
            auto diff = h - l;
            auto exclude = 0;
            if(binary_search(b.begin(), b.end(), l - diff))
            {
                exclude++;
            }
            if(binary_search(b.begin(), b.end(), h + diff))
            {
                exclude++;
            }
            if(diff % 2 == 0)
            {
                if(binary_search(b.begin(), b.end(), l + diff / 2))
                {
                    exclude++;
                }
            }
            ans += (int)b.size() - exclude;
        }
    }
    cout << ans << endl;
    return 0;
}
