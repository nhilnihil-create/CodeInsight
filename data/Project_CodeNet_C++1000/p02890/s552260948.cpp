#include <bits/stdc++.h>

using namespace std;

#define int long long
// #define double long double
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define FORR(i, a, b) for(ll i = (a); i > (b); --i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define REPR(i, n) for(ll i = n; i >= 0; i--)
#define FOREACH(x, a) for(auto &(x) : (a))
#define VECCIN(x)                                                              \
    for(auto &youso_ : (x)) cin >> youso_
#define bitcnt(x) __builtin_popcount(x)
#define lbit(x) __builtin_ffsll(x)
#define rbit(x) __builtin_clzll(x)
#define SZ(x) ((ll)(x).size())
#define fi first
#define se second
#define All(a) (a).begin(), (a).end()
#define rAll(a) (a).rbegin(), (a).rend()

template <typename T = long long> inline T IN() {
    T x;
    cin >> x;
    return (x);
}
inline void CIN() {}
template <class Head, class... Tail>
inline void CIN(Head &&head, Tail &&... tail) {
    cin >> head;
    CIN(move(tail)...);
}
#define CCIN(...)                                                              \
    char __VA_ARGS__;                                                          \
    CIN(__VA_ARGS__)
#define DCIN(...)                                                              \
    double __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define LCIN(...)                                                              \
    ll __VA_ARGS__;                                                            \
    CIN(__VA_ARGS__)
#define SCIN(...)                                                              \
    string __VA_ARGS__;                                                        \
    CIN(__VA_ARGS__)
#define Yes(a) cout << (a ? "Yes" : "No") << "\n"
#define YES(a) cout << (a ? "YES" : "NO") << "\n"
#define Printv(v)                                                              \
    {                                                                          \
        FOREACH(x, v) { cout << x << " "; }                                    \
        cout << "\n";                                                          \
    }
template <typename T = string> inline void eputs(T s) {
    cout << s << "\n";
    exit(0);
}
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val) {
    std::fill((T *)array, (T *)(array + N), val);
}

template <typename T> using PQG = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using PQ = priority_queue<T>;

typedef long long ll;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<ll, ll> PL;
typedef vector<PL> VPL;
typedef vector<bool> VB;
typedef vector<double> VD;
typedef vector<string> VS;

const int INF = 1e9;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;
const ll LINF = 1e18;
// const double PI = atan(1.0) * 4.0;
const ll dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
#define PI 3.141592653589793238

ll N;

signed main() {
    cin >> N;
    VL cnt(N + 1), ccnt(N + 1);
    REP(i, N) {
        LCIN(A);
        cnt[A]++;
    }
    FOR(num, 1, N + 1) { ccnt[cnt[num]]++; }
    VL val(N + 1), rval(N + 2);
    REP(i, N + 1) { val[i] = i * ccnt[i] + (i ? val[i - 1] : 0); }
    REPR(i, N + 1) { rval[i] = ccnt[i] + (i == N ? 0 : rval[i + 1]); }
    auto f = [val, rval](ll X) { return (val[X] + X * rval[X + 1]) / X; };
    FOR(k, 1, N + 1) {
        ll lb = 1, ub = N + 1;
        if(f(1) < k) {
            cout << 0 << "\n";
            continue;
        }
        while(ub - lb > 1) {
            ll mid = (ub + lb) / 2;
            if(f(mid) >= k)
                lb = mid;
            else
                ub = mid;
        }
        cout << lb << "\n";
    }
}
