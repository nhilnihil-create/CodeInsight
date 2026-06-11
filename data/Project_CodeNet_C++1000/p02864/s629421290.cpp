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

constexpr LL INF = 1LL << 60;

void solve() {
    int n,K;
    cin >> n >> K;
    VLL h(n);
    REP(i,0,n) cin >> h[i];
    VVLL dp(n+1,VLL(n+1, INF));
    dp[0][0] = 0;
    REP(i,0,n) {
        REP(j,0,i+1) {
            REP(k,1,n+1) {
                dp[i+1][k] = min(dp[i+1][k], dp[j][k-1] + max(0LL, h[i] - (j > 0 ? h[j-1] : 0)));
            }
        }
    }
    LL ans = INF;
    REP(i,0,n+1) ans = min(ans, dp[i][n-K]);
    cout << ans << endl;
}

int main() {
    solve();
    
    return 0;
}