//test!!!!!!!!!!!!!!!!!

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

// 1 <= k <= n <= 10^7
#define CNKMAX 100003
class CNK1 {
    std::vector<long long> fac, finv, inv;
    int MOD;
public:
    CNK1(int mod = 1000000007): MOD(mod), fac(CNKMAX), finv(CNKMAX), inv(CNKMAX) {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < CNKMAX; i++){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
    int get(const int &n, const int &k) const {
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
};

long long power(long long x, long long n, long long mod = 1000000007) {
    if (n == 0) return 1;
    if (n % 2 == 0) return power(x * x % mod, n/2, mod);
    else return x * power(x, n-1, mod) % mod;
}

void solve() {
    string l;
    cin >> l;
    int len = l.size();
    CNK1 cnk;
    VI cs(100000+2);
    LL ans = 0;
    int c1 = 0;
    REP(i,0,len) {
        if (l[i] == '0') continue;
        LL sum = power(3, len - i - 1);
        sum = (sum * power(2, c1)) % MOD;
        ans = (ans + sum) % MOD;
        ++c1;
    }
    ans = (ans + power(2, c1)) % MOD;

    cout << ans << endl;
}

int main() {
    solve();
    
    return 0;
}
