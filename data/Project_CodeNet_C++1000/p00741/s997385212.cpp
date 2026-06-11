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

VVI C;
vector<vector<bool>> used;
int MH, MW;
int dh[] = {0, 0, -1, 1, -1, -1, 1, 1};
int dw[] = {-1, 1, 0, 0, -1, 1, -1, 1};
bool inside(int h, int w) {
    return 0 <= h && h < MH && 0 <= w && w < MW;
}
bool dfs(int h, int w) {
    if (used[h][w]) return false;
    used[h][w] = true;
    REP(i, 8) {
        int nh = h + dh[i], nw = w + dw[i];
        if (!inside(nh, nw)) continue;
        if (C[nh][nw] == 1) dfs(nh, nw);
    }
    return true;
}
void solve(int w, int h) {
    MH = h; MW = w;
    C.resize(h, VI(w));
    used.resize(h, vector<bool>(w, false));
    REP(i, h)REP(j, w) cin >> C[i][j];
    int cnt = 0;
    REP(i, h)REP(j, w) {
        if (C[i][j] == 1) cnt += dfs(i, j);
    }
    cout << cnt << endl;
    used.clear();
    C.clear();
    return;
}

int main(void) {
    int n, p, m, w, h;
    string s;
    int a, b, c;
    while (cin >> w >> h) {
        if (w == 0 && h == 0) return 0;
        solve(w, h);
        //return 0;
    }
}