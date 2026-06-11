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

bool solve(LL &t, VLL a, LL &n, LL &m, LL &v, LL &p) {
    a[t] += m;
    LL rem = m * (v-1);
    REP(i,0,p-1) {
        a[n-1-i] += m;
        rem -= m;
    }

    REP(i,0,t) {
        rem -= m;
        a[i] += m;
    }
    //if (rem <= 0) return true;
    REP(i,t+1,n-p+1) {
        if (rem <= 0) {
            while (i < n && a[i] <= a[t]) ++i;
            return n - i + 1 <= p;
        }
        LL diff = max(0LL, min(rem, a[t] - a[i]));
        //dump(diff);
        rem -= diff;
        a[i] += diff;
    }
    //dump(rem);

    return rem <= 0;
}

long long meguru_bin(VLL &a, LL &n, LL &m, LL &v, LL &p) {
    long long ok = n - p + 1;
    long long ng = -1;

    while (abs(ok - ng) > 1) {
        long long mid = ng + (ok - ng) / 2;
        //dump(mid);
        if (solve(mid,a,n,m,v,p)) ok = mid;
        else ng = mid;
    }
    //dump(ok);
    return ok;
}

void solve() {
    LL n,m,v,p;
    cin >> n >> m >> v >> p;
    VLL a(n);
    REP(i,0,n) cin >> a[i];
    sort(all(a));

    cout << n - meguru_bin(a,n,m,v,p) << endl;
}

signed main() {
    solve();
    
    return 0;
}