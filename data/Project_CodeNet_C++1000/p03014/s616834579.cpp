// 問題の URL を書いておく
// https://atcoder.jp/contests/abc129/tasks/abc129_d

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
    int h, w;
    cin >> h >> w;
    vector<string> g(h);
    rep(i, h)
    {
        cin >> g[i];
    }
    vector<vector<vector<int>>> c(h, vector<vector<int>>(w, vector<int>(2, 0)));

    rep(i, h)
    {
        int count = 0;
        rep(j, w + 1)
        {
            if(j == w || g[i][j] == '#')
            {
                rep(k, count)
                {
                    c[i][j - k - 1][0] = count;
                }
                count = 0;
            }
            else
            {
                count++;
            }
        }
    }

    rep(i, w)
    {
        int count = 0;
        rep(j, h + 1)
        {
            if(j == h || g[j][i] == '#')
            {
                rep(k, count)
                {
                    c[j - k - 1][i][1] = count;
                }
                count = 0;
            }
            else
            {
                count++;
            }
        }
    }

    int ans = 0;
    rep(i, h)
    {
        rep(j, w)
        {
            ans = max(ans, c[i][j][0] + c[i][j][1] - 1);
        }
    }
    cout << ans << endl;

#if 0
    rep(i, h)
    {
        rep(j, w)
        {
            cout << c[i][j][0];
        }
        cout << endl;
    }

    rep(i, h)
    {
        rep(j, w)
        {
            cout << c[i][j][1];
        }
        cout << endl;
    }
#endif
    return 0;
}
