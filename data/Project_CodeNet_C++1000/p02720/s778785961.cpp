// 問題の URL を書いておく
// https://atcoder.jp/contests/abc161/tasks/abc161_d

#include <algorithm>
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

void f(string s, vector<string>& ans, int maxLen)
{
    if(s.size() == 0)
    {
        abort();
    }
    ans.push_back(s);
    if((int)s.size() == maxLen)
    {
        return;
    }
    auto t = (*s.rbegin());
    if(t > '0')
    {
        auto na = s + (char)(t - 1);
        f(na, ans, maxLen);
    }
    f(s + t, ans, maxLen);
    if(t < '9')
    {
        auto na = s + (char)(t + 1);
        f(na, ans, maxLen);
    }
}

int main(int, const char**)
{
    int k;
    cin >> k;

    vector<string> ans;
    rep(i, 9)
    {
        auto a = string(1, '0' + i + 1);
        f(a, ans, 10);
    }

    sort(ans.begin(), ans.end(), [](const auto& a, const auto& b){
        if(a.size() == b.size())
        {
            return a < b;
        }
        return a.size() < b.size();
    });

    if(k <= (int)ans.size())
    {
        cout << ans[k - 1] << endl;
    }
    else
    {
        printf("over, ans.size = %zu, k = %d\n", ans.size(), k);
    }

    return 0;
}
