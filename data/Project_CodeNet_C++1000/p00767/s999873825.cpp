#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <complex>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <bitset>
#include <ctime>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <sstream>
#include <fstream>

using namespace std;
#define REP(i, n) for (int (i) = 0; (i) < (n); (i)++)
#define FOR(i, a, b) for (int (i) = (a); (i) < (b); (i)++)
#define RREP(i, a) for(int (i) = (a) - 1; (i) >= 0; (i)--)
#define FORR(i, a, b) for(int (i) = (a) - 1; (i) >= (b); (i)--)
#define DEBUG(C) cerr << #C << " = " << C << endl;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<LL>;
using VVL = vector<VL>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
using PLL = pair<LL, LL>;
using VPII = vector<PII>;
#define ALL(a) begin((a)), end((a))
#define RALL(a) rbegin((a)), rend((a))
#define SORT(a) sort(ALL((a)))
#define RSORT(a) sort(RALL((a)))
#define REVERSE(a) reverse(ALL((a)))
#define MP make_pair
#define FORE(a, b) for (auto &&a : (b))
#define FIND(s, e) ((s).find(e) != (s).end())
#define EB emplace_back

const int INF = 1e9;
const int MOD = INF + 7;
const LL LLINF = 1e18;

map<PII, int> mp;
void solve(int h, int w) {
    int n = h * h + w * w;
    pair<PII, int> ans = MP(MP(INF, INF), INF);
    FORE(el, mp) {
        if (MP(h, w) == el.first) continue;
        if (n > el.second) continue;
        if (n == el.second && h >= el.first.first) continue;
        if (el.second < ans.second) {
            ans = el;
        } else if (el.second == ans.second && ans.first.first > el.first.first) {
            ans = el;
        }
    }

    cout << ans.first.first << " " << ans.first.second << endl;
}

signed main(void) {
    int n, m, p, a, b, c, x, y, z, q;
    string s;
    REP(h, 150) FOR(w, h + 1, 150) {
        mp[MP(h + 1, w + 1)] = pow(h + 1, 2) + pow(w + 1, 2);
    }
    while (cin >> n >> m, n && m) {
        solve(n, m);
        //return 0;
    }
}