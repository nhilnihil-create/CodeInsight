
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
    vector<vector<int>> a(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (a[j][k] == b)
                {
                    a[j][k] = -1;
                }
            }
        }
    }
    bool ans = false;
    for (int i = 0; i < 3; i++)
    {
        bool flag = false;
        for (int j = 0; j < 3; j++)
        {
            if (a[i][j] != -1)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            ans = true;
        }
    }

    if (a[0][0] == -1 && a[1][1] == -1 && a[2][2] == -1)
    {
        ans = true;
    }
    if (a[2][0] == -1 && a[1][1] == -1 && a[0][2] == -1)
    {
        ans = true;
    }
    for (int i = 0; i < 3; i++)
    {
        bool flag = false;
        for (int j = 0; j < 3; j++)
        {
            if (a[j][i] != -1)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            ans = true;
        }
    }
    if (ans)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
