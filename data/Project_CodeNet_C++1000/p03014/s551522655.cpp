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
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                   \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;

using Graph = vector<vector<int>>;

int h, w;
int dist;
int dist_;

void dfs1(int i, int j, vector<string> &s, vector<vector<int>> &dist1)
{
    if (j < w && s[i][j] == '.')
    {
        dist++;
        dfs1(i, j + 1, s, dist1);
        dist1[i][j] = dist;
    }
    if (j >= w || s[i][j] == '#')
    {
        return;
    }
}
void dfs2(int i, int j, vector<string> &s, vector<vector<int>> &dist2)
{
    if (i < h && s[i][j] == '.')
    {
        dist_++;
        dfs2(i + 1, j, s, dist2);
        dist2[i][j] = dist_;
    }
    if (i >= h || s[i][j] == '#')
    {
        return;
    }
}

int main()
{
    cin >> h >> w;
    vector<string> s(h);
    vector<vector<int>> dist1(h, vector<int>(w, -1));
    vector<vector<int>> dist2(h, vector<int>(w, -1));
    // cout << "AAAAAAAAAAAA" << endl;
    for (int i = 0; i < h; i++)
    {
        cin >> s[i];
    }
    // cout << "AAAAAAAAAAAA" << endl;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (s[i][j] == '.' && dist1[i][j] == -1)
            {
                dist = 0;
                dfs1(i, j, s, dist1);
            }
            if (s[i][j] == '.' && dist2[i][j] == -1)
            {
                dist_ = 0;
                dfs2(i, j, s, dist2);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            ans = max(ans, dist1[i][j] + dist2[i][j]);
        }
    }
    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //     {
    //         cout << dist1[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "-----------" << endl;
    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < w; j++)
    //     {
    //         cout << dist2[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans - 1 << endl;

    return 0;
}