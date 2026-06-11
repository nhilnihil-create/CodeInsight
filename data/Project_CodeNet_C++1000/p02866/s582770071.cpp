#include <bits/stdc++.h>
#include <random>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
//#define ll __int128
//#define int ll
//#define int ll
//#define char ll
#define double ld
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<vvc> vvvc;
typedef pair<int, int> pii;
typedef pair<pii, pii> piii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<string> vst;
typedef vector<vst> vvst;
typedef pair<ld, ld> pld;

#define inmin(a, b) a = min(a, (b))
#define inmax(a, b) a = max(a, (b))
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define sqr(x) ((x) * (x))
#define fori(i, n) for(int i = 0; i < int(n); ++i)
#define SZ(a) ((int)((a).size()))
#define triple(T) tuple<T, T, T>
#define quad(T) tuple<T, T, T, T>
#define watch(x) cerr << (#x) << " = " << (x) << endl;

#ifdef MAX_HOME
#define cerr cout
#else
#define cerr if (false) cerr
#endif

const double PI = 2 * acos(0.0);
#define rand shittttty_shit
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());

const string DIGITS = "0123456789";
const string ALPH = "abcdefghijklmnopqrstuvwxyz";


template<class T0, class T1>
inline ostream &operator<<(ostream &out, pair<T0, T1> &a) {
    return out << "{" << a.first << ", " << a.second << "}";
}

template<class T0, class T1>
inline istream &operator>>(istream &in, pair<T0, T1> &a) {
    return in >> a.first >> a.second;
}

template<class T0, class T1, class T2>
inline ostream &operator<<(ostream &out, tuple<T0, T1, T2> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << "}";
}

template<class T0, class T1, class T2, class T3>
inline ostream &operator<<(ostream &out, tuple<T0, T1, T2, T3> &a) {
    return out << "{" << get<0>(a) << ", " << get<1>(a) << ", " << get<2>(a) << ", " << get<3>(a) << "}";
}

template<class T>
inline ostream &operator<<(ostream &out, vector<T> &a) {
    out << "[";
    fori (i, a.size())out << a[i] << vector<string>{", ", "]  "}[i + 1 == a.size()];
    return out;
}


void smain();


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef MAX_HOME
    freopen("input.txt", "r", stdin);
    clock_t start = clock();
#endif
    cout << setprecision(12) << fixed;
    smain();
#ifdef MAX_HOME
    cout << "\n\nTOTAL EXECUTION TIME: " << float(clock() - start) / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

const int M = 998244353;

int pw(int a, int n = M - 2) {
    int ret = 1;
    while (n) {
        if (n & 1)
            ret = (ll) ret * a % M;
        n >>= 1;
        a = (ll) a * a % M;
    }
    return ret;
}

const int N = 2e5 + 10;

int fact[N], rfact[N];

int ncr(int n, int k) {
    if (k < 0 || k > n)
        return 0;
    return (ll) fact[n] * rfact[n - k] % M * rfact[k] % M;
}

int calc(int pl, int obj) {
    return ncr(pl + obj - 1, pl - 1);
}

void bad() {
    cout << "0";
    exit(0);
}

void smain() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = (ll) fact[i - 1] * i % M;
    }
    rfact[N - 1] = pw(fact[N - 1]);
    for (int i = N - 2; i >= 0; --i) {
        rfact[i] = (ll) (i + 1) * rfact[i + 1] % M;
    }

    int n;
    cin >> n;
    vi cnt(n, 0);
    fori (i, n) {
        int d;
        cin >> d;
        if (i == 0 && d != 0) {
            bad();
        }
        cnt[d]++;
    }
    int all = 1;
    if (cnt[0] != 1)
        bad();
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        if (cnt[i] == 0)
            break;
        all += cnt[i];
        ans = (ll) ans * pw(cnt[i - 1], cnt[i]) % M;
    }
    cout << ans * (all == n);
}