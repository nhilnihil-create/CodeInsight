/* -> Written by <-
   -----------
  |K_A_Z_A_M_A|
  |___________|
  |    _    |
  |   (^_^)   |
  |  /( | )\  |
  |____|_|____|
    H O A N G
*/

#define Task ""
#define F first
#define S second
#define push_back pb
#define bit(x, i) (x >> i) & 1
#define inf 1e9 + 7
#define INF 1e18 + 7

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdio>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int maxn = 2e5 + 5;

int n, m;
ll a[maxn], b[maxn], sa[maxn], sb[maxn];
ll k;

void Solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i ++) cin >> a[i], sa[i] = sa[i-1] + a[i];
    for (int i = 1; i <= m; i ++) cin >> b[i], sb[i] = sb[i-1] + b[i];
    int res = 0;
    for (int i = 0; i <= n; i ++)
    {
        if (sa[i] > k) break;
        ll cur = k - sa[i];
        int l = 0, r = m + 1;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (sb[mid] > cur) r = mid;
            else l = mid;
        }
        res = max(res, i + l);
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    if(fopen(Task".inp", "r"))
    {
        freopen(Task".inp","r",stdin);
        freopen(Task".out","w",stdout);
    }
    int test_case = 1;
//    cin >> test_case;
    while (test_case --)
        Solve();
    return 0;
}
