// 問題の URL を書いておく
// https://atcoder.jp/contests/abc159/tasks/abc159_d

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
    vector<int> a(n);
    map<int, ll> counts, comb;
    rep(i, n)
    {
        cin >> a[i];
        if(counts.find(a[i]) == counts.end())
        {
            counts[a[i]] = 0;
        }
        counts[a[i]]++;
    }
    for(auto c : counts)
    {
        auto t = c.second >= 2 ? c.second * (c.second - 1) / 2 : 0;
        comb[c.first] = t;
    }
    ll all = 0;
    for(auto c : comb)
    {
        all += c.second;
    }

    rep(i, n)
    {
        auto num = a[i];
        auto count = counts[num] - 1;
        auto nc = count >= 2 ? count * (count - 1) / 2 : 0;
        auto ans = all - comb[num] + nc;
        cout << ans << endl;
    }

    return 0;
}
