#include <string>
#include <iostream>
#include <stack>
#include <queue> // priority_queue も入ってる
#include <set>   // 要素数は size() で取得 multisetもある
#include <map>
#include <array> // sizeはコンパイル時定数で固定
#include <vector>
#include <numeric>   // accumulate, gcd
#include <algorithm> // count_ifに必要
#include <iomanip>   // cout << setprecision(15) << x で小数の出力精度を指定
#include <tuple>
#include <utility> //pair
#include <cmath>
#include <bitset>

using namespace std;
// 問題が起こるまでintは使用禁止2020-04-13
using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)

template <class InputIterator, class T>
bool contains_itr(InputIterator iterator, const T &value)
{
    if (find(iterator.begin(), iterator.end(), value) == iterator.end())
        return false;
    else
        return true;
}

template <class T>
bool contains_set(set<T> st, const T &value)
{
    if (st.find(value) == st.end())
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class InputIterator>
auto sum(InputIterator iterator)
{
    return accumulate(iterator.begin(), iterator.end(), 0);
}

// endは排他的(exclusive)なので注意
vector<ll> range(ll begin, ll end)
{
    vector<ll> result;
    for (ll i = begin; i < end; ++i)
    {
        result.push_back(i);
    }
    return result;
}

// =========ここまでテンプレ============

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    rep(i, k)
    {
        vector<ll> b(n);
        rep(j, n)
        {
            // for (ll m = max(j - a[j], ll{0}); m <= min(j + a[j], n - 1); ++m)
            // {
            //     ++b[m];
            // }
            ++b[max(j - a[j], ll{0})];
            if (j + a[j] + 1 < n)
                --b[j + a[j] + 1];
        }
        for (ll j = 1; j < n; ++j)
            b[j] += b[j - 1];
        a = b;
        if (a == vector<ll>(n, n))
        {
            // cout << 'k: ' << k << endl;
            break;
        }
    }
    rep(i, n) cout << a[i] << ' ';
    cout << endl;
}