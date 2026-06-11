#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll

template<typename T1,typename T2> inline void chmin(T1 &a, T2 b){ if(a > b) a = b; }
template<typename T1,typename T2> inline void chmax(T1 &a, T2 b){ if(a < b) a = b; }

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, -1, sizeof(p))
#if 1
#  define DBG(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#  define DBG(fmt, ...)
#endif

const ll LLINF = (1LL<<60);
const int INF = (1LL<<30);
const double DINF = std::numeric_limits<double>::infinity();
const int MOD = 1000000007;
const int MAX_N = 100010;

template <typename T> T gcd(T a, T b) { while (a) { b %= a; swap(a, b); } return b; }
template <typename T> T lcm(T a, T b) { return a / gcd(a,b) * b; }

map<ll, ll> PrimeFactor(ll n) {
    map<ll, ll> res;
    for(ll i = 2; i * i <= n; ++i) {
        while(n % i == 0) {
            ++res[i];
            n /= i;
        }
        if(LLINF / i <= i) { break; }  // オーバーフロー警察
    }
    if(n != 1) { res[n] = 1; }
    return res;
}

int N, M;
vector<int> A, B;

signed main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    A.resize(N);
    REP(i, N) {
        cin >> A[i];
        A[i] /= 2;
    }

    // 何回 2 で割れるか
    auto Check = [](int num) {
        int ret = 0;
        while(num % 2 == 0) {
            num /= 2;
            ret++;
        }
        return ret;
    };
    // 2 の個数チェック
    int check = Check(A[0]);
    REP(i, N) {
        if(check != Check(A[i])) {
            printf("0\n");
            return 0;
        }
        A[i] >>= check;
    }

    M >>= check;

    int lcm_a = 1; 
    REP(i, N) {
        lcm_a = lcm(lcm_a, A[i]);
    }

    int ans = M / lcm_a;
    ans = (ans + 1) / 2;

    printf("%lld\n", ans);

    return 0;
}
