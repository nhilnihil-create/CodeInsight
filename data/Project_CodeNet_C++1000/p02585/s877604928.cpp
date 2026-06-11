#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <memory>
#include <complex>
#include <numeric>
#include <cstdio>
#include <iomanip>
#include <random>

#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
#define RREP(i,m,n) for(int i=int(n)-1;i>=int(m);--i)
#define EACH(i,c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
//#define int long long

#ifdef LOCAL
#define DEBUG(s) cout << (s) << endl
#define dump(x)  cerr << #x << " = " << (x) << endl
#define BR cout << endl;
#else
#define DEBUG(s) do{}while(0)
#define dump(x) do{}while(0)
#define BR 
#endif
using namespace std;

using UI = unsigned int;
using UL = unsigned long;
using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

void solve() {
    LL n,k;
    cin >> n >> k;
    VLL p(n), c(n);
    REP(i,0,n) cin >> p[i];
    REP(i,0,n) --p[i];
    REP(i,0,n) cin >> c[i];
    LL ans = -(1LL<<60);
    REP(i,0,n) {
        int idx = i;
        LL sum = 0;
        // LL maxv = -1 * (1LL<<60);
        VLL ms(n);
        REP(j,0,n) {
            sum += c[p[idx]];
            idx = p[idx];
            if (j == 0) ms[j] = sum;
            else ms[j] = max(sum, ms[j-1]);
        }
        if (k <= n) {
            chmax(ans, ms[k-1]);
            continue;
        }

        int cnt = 0;
        sum = 0;
        idx = i;
        for (;;) {
            sum += c[p[idx]];
            idx = p[idx];
            ++cnt;
            if (idx == i) break;
        }
        // dump(cnt);
        if (sum < 0) {
            chmax(ans, *max_element(all(ms)));
            continue;
        }
        if (sum == 0) {
            chmax(ans, max(0LL, *max_element(all(ms))));
            continue;
        }

        LL tmp = sum * (k / cnt);
        LL rem = k % cnt;

        if (rem == 0) chmax(ans, max(tmp, tmp-sum+ms[cnt-1]));
        else chmax(ans, max(0LL, tmp) + max(0LL, ms[rem-1]));
        // dump(tmp + remv);
    }
    cout << ans << endl;
}

signed main() {
    solve();
    
    return 0;
}