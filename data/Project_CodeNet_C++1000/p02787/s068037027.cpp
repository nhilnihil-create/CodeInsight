
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
#include <functional>
using namespace std;
typedef long long ll;

#define fi first
#define se second
#define rep(i, n) for (ll i = 0; i < n; i++)
#define debugA cerr << "AAAAA" << endl
#define debug_ cerr << "-------------" << endl
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                   \
    cout << #v << endl;                \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;
#define debug_vec2(v)                         \
    cout << #v << endl;                       \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
        {                                     \
            cout << v[i][j] << " ";           \
        }                                     \
        cout << endl;                         \
    }

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
void quit(T a)
{
    cout << a << endl;
    exit(0);
}

using Graph = vector<vector<int>>;
using P = pair<int, int>;
using P1 = pair<int, pair<int, int>>; // クラスカル法とかで、{cost, {from, to}}的に使う。
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const double pi = acos(-1);

int main()
{
    int h, n;
    cin >> h >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    // dp[i]=トキの体力
    vector<int> dp(h + 10010, INF);
    dp[0] = 0;
    int ans = INF;
    for (int j = 0; j <= h + 10000; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (j - a[i] >= 0)
            {
                chmin(dp[j], dp[j - a[i]] + b[i]);
            }
            if (j >= h)
            {
                chmin(ans, dp[j]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
