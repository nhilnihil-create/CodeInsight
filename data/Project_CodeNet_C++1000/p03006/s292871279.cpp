// 問題の URL を書いておく
// https://atcoder.jp/contests/diverta2019-2/tasks/diverta2019_2_b

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

int main(int, const char**)
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    struct Info
    {
        int64_t x;
        int64_t y;
    };
    vector<Info> p(n);
    rep(i, n)
    {
        int64_t x, y;
        cin >> x >> y;
        p[i] = {x, y};
    };
    auto compare = [](const Info& a, const Info& b)
    {
        if(a.x == b.x)
        {
            return a.y < b.y;
        }
        return a.x < b.x;
    };

    sort(p.begin(), p.end(), compare);

    map<Info, int, decltype(compare)> data{compare};

    rep(i, n - 1)
    {
        for(int j = i + 1; j < n; ++j)
        {

            Info diff = {p[j].x - p[i].x, p[j].y - p[i].y};
            if(data.find(diff) == data.end())
            {
                data[diff] = 0;
            }
            data[diff]++;
        }
    }
    int mc = 1;
    for(auto d : data)
    {
        mc = max(mc, d.second);
    }
    cout << n - mc << endl;
    return 0;
}
