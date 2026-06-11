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

// bit Gausian

const int MAX_ROW = 65;     // to be set appropriately
const int MAX_COL = 100100; // to be set appropriately
struct BitMatrix {
    int H, W;
    bitset<MAX_COL> val[MAX_ROW];
    BitMatrix(int m = 1, int n = 1) : H(m), W(n) {}
    inline bitset<MAX_COL> &operator[](int i) { return val[i]; }
};

void GaussJordan(BitMatrix &A, bool is_extended = false) {
    VB used(A.H, 0);
    for(int col = 0; col < A.W; ++col) {
        if(is_extended && col == A.W - 1) break;
        int pivot = -1;
        for(int row = 0; row < A.H; ++row) {
            if(used[row]) continue;
            if(A[row][col]) {
                pivot = row;
                break;
            }
        }
        if(pivot == -1) continue;
        for(int row = 0; row < A.H; ++row) {
            if(row != pivot && A[row][col]) A[row] ^= A[pivot];
        }
        used[pivot] = true;
    }
}

signed main() {
    LCIN(N);
    VL A(N);
    VECCIN(A);
    ll mbit = 60;
    BitMatrix M(mbit, N + 1);
    bitset<60> flag;
    ll ans = 0;
    REP(b, mbit) {
        ll cnt = 0;
        REP(i, N) {
            if(A[i] >> b & 1) cnt++;
        }
        if(cnt == 0) continue;
        if(cnt & 1) {
            ans += (1LL << b);
            continue;
        }
        flag[b] = 1;
        REP(i, N) {
            if(A[i] >> b & 1) M[mbit - 1 - b][i] = 1;
        }
        M[mbit - 1 - b][N] = 1;
    }
    GaussJordan(M, true);
    REP(b, mbit) {
        if(!flag[b]) continue;
        bool ok = false;
        REP(i, N) if(M[mbit - 1 - b][i]) ok = true;
        if(!M[mbit - 1 - b][N]) ok = true;
        if(ok) {
            ans += (1LL << b) * 2;
        }
    }
    cout << ans << "\n";
}
