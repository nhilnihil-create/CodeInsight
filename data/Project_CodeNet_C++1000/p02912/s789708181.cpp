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

int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, less<int>> que;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        que.push(a);
    }
    for (int i = 0; i < m; i++)
    {
        int x = que.top();
        que.pop();
        que.push(x / 2);
    }
    ll ans = 0;
    while (!que.empty())
    {
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;

    return 0;
}
