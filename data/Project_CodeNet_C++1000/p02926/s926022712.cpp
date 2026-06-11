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

#define REP(i,m,n) for(int i=int(m);i<int(n);i++)
#define RREP(i,m,n) for(int i=int(n)-1;i>=int(m);--i)
#define EACH(i,c) for (auto &(i): c)
#define all(c) begin(c),end(c)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort(begin(c),end(c))
#define pb emplace_back
#define MP make_pair
#define SZ(a) int((a).size())

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
using LL = long long int;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VS = vector<string>;
using PII = pair<int,int>;
using VP = vector<PII>;

//struct edge {int from, to, cost;};

constexpr double EPS = 1e-10;
//constexpr double PI  = acos(-1.0);
//constexpr int INF = INT_MAX;
constexpr int MOD = 1'000'000'007;
//inline void modAdd(LL &l, LL &r) {l = (l + r) % MOD;}

template<class T> inline T sqr(T x) {return x*x;}

void solve() {
    int n;
    cin >> n;
    vector<pair<LL,LL>> r(n);
    REP(i,0,n) cin >> r[i].first >> r[i].second;
    sort(all(r), [](auto &l, auto &r) {
        return atan2(l.second, l.first) < atan2(r.second, r.first);
    });
    vector<pair<LL,LL>> ru(n+1);
    REP(i,0,n) {
        ru[i+1].first += ru[i].first + r[i].first;
        ru[i+1].second += ru[i].second + r[i].second;
    }
    double ans = 0;
    REP(i,0,n) REP(j,0,n) {
        LL sx,sy;
        if (i <= j) {
            sx = ru[j+1].first - ru[i].first;
            sy = ru[j+1].second - ru[i].second;
        } else {
            sx = ru[n].first - ru[i].first + ru[j+1].first;
            sy = ru[n].second - ru[i].second + ru[j+1].second;
        }

        ans = max(ans, sqrt(sx * sx + sy * sy));
    }
    printf("%.10lf\n", ans);
}

int main() {
    solve();
    
    return 0;
}