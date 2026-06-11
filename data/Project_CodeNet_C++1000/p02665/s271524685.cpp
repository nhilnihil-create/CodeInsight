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
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }

    // n == 0 での例外処理
    if (n == 0)
    {
        if (a[0] == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
        return 0;
    }
    // 根についての例外処理。
    if (a[0] != 0)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> MAX(n + 1); // 各深さで最大何個のノードを持ちうるのかを保持。

    // はじめは、深い方からMAXを更新。あとで浅い方からも更新する。
    MAX[n] = a[n];
    for (int i = n - 1; i >= 0; i--)
    {
        MAX[i] = MAX[i + 1] + a[i];
    }

    MAX[0] = 1;
    ll ans = 1;
    // 浅い方からMAXを更新。
    for (int i = 1; i <= n; i++)
    {
        MAX[i] = min((MAX[i - 1] - a[i - 1]) * 2, MAX[i]);
        ans += MAX[i];
        if (MAX[i] <= 0)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    if(MAX[n] < a[n]){
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;
    // debug_vec(MAX);

    return 0;
}
