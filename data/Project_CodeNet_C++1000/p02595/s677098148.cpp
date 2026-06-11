#pragma GCC optimize("O3")
#define _GLIBCXX_DEBUG

#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define endl '\n'
#define fcout cout << fixed << setprecision(15)

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int i = 0; (i) < (int)(n); i++)

using ll    = long long;
using ld    = long double;
using Pii   = pair<int, int>;
using Pll   = pair<ll, ll>;

constexpr int MOD       = (int)1e9 + 7;
constexpr int INF_int   = (int)(1 << 30);
constexpr ll INF_ll     = (ll)1e18 + 1;
constexpr ld PI         = 3.141592653589793L;

template<typename T1, typename T2> inline bool chmax(T1 &a, T2 b) { return a < b && (a = b, true); }
template<typename T1, typename T2> inline bool chmin(T1 &a, T2 b) { return a > b && (a = b, true); }

//vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
//vector<int> dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };

/*追加部分*/



/*main関数*/

signed main() {
    int n, d, ans = 0; scanf("%d%d", &n, &d);
    rep(i, n){
        int x, y;
        scanf("%d%d", &x, &y);
        if(hypot(x, y) <= d) ans++;
    }

    printf("%d\n", ans);
return 0;
}
