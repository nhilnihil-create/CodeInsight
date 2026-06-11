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
    int n, x, y;
    cin >> n >> x >> y;
    x--; y--;
    vector<vector<int>> g(n);
    rep(i, n - 1)
    {
        g[i].push_back(i + 1);
        g[i + 1].push_back(i);
    }
    g[x].push_back(y);
    g[y].push_back(x);

    vector<int> ans(n, 0);
    struct Data
    {
        int index;
        int distance;
    };
    queue<Data> q;
    rep(i, n - 1)
    {
        vector<bool> visit(n, false);
        q.push({i, 0});
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();

            if(visit[t.index])
            {
                continue;
            }
            visit[t.index] = true;
            if(i < t.index)
            {
                ans[t.distance]++;
            }
            for(auto next : g[t.index])
            {
                if(visit[next])
                {
                    continue;
                }
                q.push({next, t.distance + 1});
            }
        }
    }

    rep(i, n - 1)
    {
        cout << ans[i + 1] << endl;
    }

    return 0;
}
