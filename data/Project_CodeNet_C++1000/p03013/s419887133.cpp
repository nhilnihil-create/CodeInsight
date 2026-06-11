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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m);
    vector<ll> v(n + 1, 0);
    v[0] = 1;
    v[1] = 1;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
        v[a[i]] = -1;
    }
    for (int i = 2; i < n + 1; i++)
    {
        if (v[i] != -1)
        {
            (v[i] = max(v[i - 1], 0ll) + max(v[i - 2], 0ll)) %= 1000000007;
        }
    }
    cout << max(v[n], 0ll) << endl;
    // debug_vec(v);

    return 0;
}
