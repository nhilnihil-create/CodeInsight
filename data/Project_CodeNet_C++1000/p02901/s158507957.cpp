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
#define debug_vec2(v)                         \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
        {                                     \
            cout << v[i][j] << " ";           \
        }                                     \
        cout << endl;                         \
    }

using Graph = vector<vector<int>>;
using P = pair<int, int>;
const int INF = 1001001001;
const double pi = acos(-1);

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> c(m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i] = x;
        int SUM = 0;
        for (int j = 0; j < y; j++)
        {
            int z;
            cin >> z;
            z--;
            SUM |= (1 << z);
        }
        c[i] = SUM; // c[i] = 6 なら、1つめと2つめと3つめを開けられる。
    }

    vector<int> dp(1 << n, INF);
    dp[0] = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp[i | c[j]] = min(dp[i | c[j]], dp[i] + a[j]);
        }
    }

    if (dp[(1 << n) - 1] == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[(1 << n) - 1] << endl;
    }

    return 0;
}
