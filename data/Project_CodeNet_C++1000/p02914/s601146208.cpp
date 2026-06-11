// May this submission get accepted!

#pragma GCC optimize ("O3")
#pragma GCC target ("tune=native")
#pragma GCC target ("avx")

#include <bits/stdc++.h>

// 汎用マクロ
#define ALL_OF(x) (x).begin(), (x).end()
#define REP(i,n) for (long long i=0, i##_len=(n); i<i##_len; i++)
#define RANGE(i,is,ie) for (long long i=(is), i##_end=(ie); i<=i##_end; i++)
#define DSRNG(i,is,ie) for (long long i=(is), i##_end=(ie); i>=i##_end; i--)
#define UNIQUE(v) do { sort((v).begin(), (v).end()); (v).erase(unique((v).begin(), (v).end()), (v).end()); } while (false)
template<class T> bool chmax(T &a, const T &b) {if (a < b) {a = b; return true;} return false; }
template<class T> bool chmin(T &a, const T &b) {if (a > b) {a = b; return true;} return false; }
#define INF 0x7FFFFFFF
#define LINF 0x7FFFFFFFFFFFFFFFLL
#define Yes(q) ((q) ? "Yes" : "No")
#define YES(q) ((q) ? "YES" : "NO")
#define Possible(q) ((q) ? "Possible" : "Impossible")
#define POSSIBLE(q) ((q) ? "POSSIBLE" : "IMPOSSIBLE")
#define DUMP(q) cerr << "[DEBUG] " #q ": " << (q) << " at " __FILE__ ":" << __LINE__ << endl
#define DUMPALL(q) do { cerr << "[DEBUG] " #q ": ["; REP(i, (q).size()) { cerr << (q)[i] << (i == i_len-1 ? "" : ", "); } cerr << "] at " __FILE__ ":" << __LINE__ << endl; } while (false)
template<class T> T gcd(const T &a, const T &b) { return a < b ? gcd(b, a) : b ? gcd(b, a % b) : a; }
template<class T> T lcm(const T &a, const T &b) { return a / gcd(a, b) * b; }

// gcc拡張マクロ
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll

// エイリアス
#define DANCE_ long
#define ROBOT_ unsigned
#define HUMAN_ signed
#define CHOKUDAI_ const
using  ll = DANCE_ HUMAN_ DANCE_;
using ull = DANCE_ ROBOT_ DANCE_;
using cll = DANCE_ DANCE_ CHOKUDAI_;
using  ld = long double;
using namespace std;

// モジュール
ll msb(ll x) {
    ll r = 0;
    while (x) {
        x >>= 1;
        r++;
    }
    return r-1;
}

// 処理内容
int main() {
    
    ull n; cin >> n;
    vector<ull> a(n);
    REP(i, n) cin >> a[i];

    ull axor = 0;
    REP(i, n) {
        axor ^= a[i];
    }

    vector<ull> a2 = a;
    REP(i, n) a2[i] &= ~axor;

    REP(i, n) {
        sort(a2.begin() + i, a2.end(), greater<ll>());
        if (!a2[i]) break;
        ull mask = 1ULL << msb(a2[i]);
        REP(j, n) if (i != j) {
            if (mask & a2[j]) {
                a2[j] ^= a2[i];
            }
        }
    }
    ull rem = accumulate(ALL_OF(a2), 0ULL, [](ull x, ull y) {
        return x ^ y;
    });

    // cerr << "[DEBUG] MATRIX:" << endl;
    // REP(i, n) {
    //     cerr << bitset<60>(a2[i]) << endl;
    // }

    cout << (axor ^ rem) + rem << endl;

    
}