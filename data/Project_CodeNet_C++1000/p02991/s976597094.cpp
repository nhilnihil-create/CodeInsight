#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
#include <ctime>
#include <tuple>
#include <bitset>
#include <assert.h>
#include <deque>
using namespace std;

/*
using PAIR = pair<string, int>;
sort(sp.begin(), sp.end(), [](PAIR l, PAIR r){
        return l.first<r.first || (l.first==r.first && l.second > r.second);
        });
*/

typedef long long ll;

#define fi first
#define se second
#define rep(i, n) for (ll i = 0; i < n; i++)
#define debugA() cerr << "AAAAA" << endl
#define debug_() cerr << "-------------" << endl
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                   \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;

using Graph = vector<vector<int>>;

int main()
{
    int n, m;
    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }
    int s, t;
    cin >> s >> t;
    s--, t--;

    // BFSして、二次元dpする。
    vector<vector<int>> dp(n, vector<int>(3, -1));
    queue<int> que;
    que.push(s);
    dp[s][0] = 0;
    while (!que.empty())
    {
        int v = que.front();
        que.pop();
        for (auto nv : G[v])
        {
            for (int j = 0; j < 3; j++)
            {
                if (dp[v][j] != -1 && dp[nv][(j + 1) % 3] == -1)
                {
                    que.push(nv);
                    dp[nv][(j + 1) % 3] = dp[v][j] + 1;
                }
            }
        }
    }
    if (dp[t][0] == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[t][0] / 3 << endl;
    }

    return 0;
}
