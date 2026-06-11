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

constexpr double EPS = 1e-10;
//constexpr double PI  = acos(-1.0);
//constexpr int INF = INT_MAX;
constexpr int MOD = 1'000'000'007;
//inline void modAdd(LL &l, LL &r) {l = (l + r) % MOD;}

template<class T> inline T sqr(T x) {return x*x;}

void solve() {
    LL n;
    cin >> n;
    if (n < 4) {
        cout << n - 1 << endl;
        return;
    }


    LL ans = 2;
    for (LL i = 2; i * i <= n; ++i) {
        //cerr << i << " " << n % i << endl;
        if (n % i == 1) ++ans;
        if (i != n / i && n % (n / i) == 1) ++ans;
        if (n % i == 0) {
            LL v = n;
            while (v % i == 0) v /= i;
            if (v % i == 1) {
                ++ans;
            }
        }
    }
    cout << ans << endl;
    dump(ans);
}

signed main() {
    solve();
    
    return 0;
}