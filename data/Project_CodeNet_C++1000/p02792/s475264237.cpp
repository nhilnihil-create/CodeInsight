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

int get_high(int n)
{
    while (true)
    {
        if (n / 10 == 0)
        {
            return n;
        }
        else
        {
            n /= 10;
        }
    }
}

int get_low(int n)
{
    return n % 10;
}

int get_digit(int n)
{
    int ans = 0;
    while (n != 0)
    {
        ans++;
        n /= 10;
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    int HIGH = get_high(n);
    int LOW = get_low(n);
    int DIGIT = get_digit(n);
    vector<int> a(DIGIT);
    int tmp = n;
    for (int i = 0; i < DIGIT; i++)
    {
        a[i] = tmp % 10;
        tmp /= 10;
    }
    if (DIGIT == 1)
    {
        cout << n << endl;
        return 0;
    }
    ll ans = 0;
    vector<int> vec(n + 1, 0);
    vector<vector<int>> table(10, vector<int>(10, 0));
    for (int i = 1; i <= n; i++)
    {
        int high, low, digit;
        low = get_low(i);
        high = get_high(i);
        table[low][high]++;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            ans += table[i][j] * table[j][i];
        }
    }
    cout << ans << endl;

    return 0;
}
