#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
typedef long long ll;
const long double PI = (acos(-1));
const long long MOD = 1000000007;

static const int  MAX_INT = std::numeric_limits<int>::max();
static const long MAX_LONG = std::numeric_limits<long>::max();
static const ll   MAX_LL = std::numeric_limits<long long>::max();

#define rep(i,n) REP(i,0,n)
#define REP(i,x,n) for(int i=x;i<n;++i)


///////////////////////////////////////////////////
// ------------------- utils ------------------- //
///////////////////////////////////////////////////
// change min/max
template<class T> inline bool chMin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chMax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// initalisation of the binominal coefficient
void COMBinit(std::vector<long long>& fac, std::vector<long long>& finv, std::vector<long long>& inv, int n, int MOD) {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < n; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// binominal coefficient: nCk
// http://drken1215.hatenablog.com/entry/2018/06/08/210000
long long COMB(int n, int k, int MOD) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    std::vector<long long> fac(n + 1), finv(n + 1), inv(n + 1);
    COMBinit(fac, finv, inv, n + 1, MOD);
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

///////////////////////////////////////////////////
// ------------------- main -------------------- //
///////////////////////////////////////////////////
void Main() {
    ll S; cin >> S;
    if (S < 3) {
        cout << 0 << endl;
        return;
    }
    
    ll maxN = S / 3;
    ll cnt = 1;
    for (ll i = 2; i <= maxN; ++i) {
        ll slot = S - 3 * i;
        cnt = (cnt + COMB(slot + i - 1, i - 1, MOD)) % MOD;
    }

    cout << cnt << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout << std::fixed << std::setprecision(15);
    Main();

    double tmp;
    cin >> tmp;

    return 0;
}
