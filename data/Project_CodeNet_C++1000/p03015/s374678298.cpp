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

using Graph = vector<vector<int>>;
using P = pair<int, int>;
using P1 = pair<int, pair<int, int>>; // クラスカル法とかで、{cost, {from, to}}的に使う。
const ll INF = 1001001001001001001;
const double pi = acos(-1);

int main()
{
    string s;
    cin >> s;
    ll n = s.size();
    ll mod = 1000000007;
    vector<vector<ll>> dp(n, vector<ll>(2, 0));
    // dp[i][0]は、i番目の文字までで和がl未満確定。
    // dp[i][1]は、i番目の文字まで和がlと一致。

    dp[0][0] = 1;
    dp[0][1] = 2;
    for (ll i = 1; i < n; i++)
    {
        if (s[i] == '0')
        {
            dp[i][0] = dp[i - 1][0] * 3;
            dp[i][1] = dp[i - 1][1];
        }
        else
        {
            // s[i] == 1
            dp[i][0] = dp[i - 1][0] * 3 + dp[i - 1][1];
            dp[i][1] = dp[i - 1][1] * 2;
        }
        dp[i][0] %= mod;
        dp[i][1] %= mod;
    }
    cout << (dp[n - 1][0] + dp[n - 1][1]) % mod << endl;

    return 0;
}
