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
    vector<int> edge(n - 1, 0);
    int nc = 0;
    vector<vector<int*>> v(n);
    rep(i, n - 1)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        v[a].push_back(&edge[i]);
        v[b].push_back(&edge[i]);
    }
    rep(i, n)
    {
        auto es = v[i];
        nc = max(nc, (int)es.size());
        vector<bool> used(nc + 1, false);
        for(auto e : es)
        {
            if(*e != 0)
            {
                used[*e] = true;
            }
        }
        int c = 1;
        for(auto e : es)
        {
            if(*e != 0)
            {
                continue;
            }
            while(used[c])
            {
                c++;
            }
            *e = c;
            used[c] = true;
        }
    }

    cout << nc << endl;
    rep(i, n - 1)
    {
        cout << edge[i] << endl;
    }
    return 0;
}
