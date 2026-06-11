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
using P = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, m;
    cin >> a >> b >> m;
    vector<int> v1(a);
    vector<int> v2(b);
    int MIN1 = 1001001001;
    int MIN2 = 1001001001;
    for (int i = 0; i < a; i++)
    {
        cin >> v1[i];
        MIN1 = min(MIN1, v1[i]);
    }
    for (int i = 0; i < b; i++)
    {
        cin >> v2[i];
        MIN2 = min(MIN2, v2[i]);
    }
    int ans = MIN1 + MIN2;
    for (int i = 0; i < m; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        ans = min(ans, v1[x] + v2[y] - c);
    }
    cout << ans << endl;

    return 0;
}
