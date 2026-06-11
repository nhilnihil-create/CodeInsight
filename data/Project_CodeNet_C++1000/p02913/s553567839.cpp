#include <bits/stdc++.h>
#include <algorithm>
// #include <atcoder/all>
#include <functional>
#include <map>
#include <queue>
#include <set>
#include <stack>
using namespace std;
// using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
#define REP(i, m, n) for (ll(i) = (ll)(m); i < (ll)(n); ++i)
#define REP2(i, m, n) for (ll(i) = (ll)(n)-1; i >= (ll)(m); --i)
#define rep(i, n) REP(i, 0, n)
#define rep2(i, n) REP2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define rall(hoge) (hoge).rbegin(), (hoge).rend()
#define en '\n'
using Edge = pair<ll, ll>;
using Graph = vector<vector<Edge>>;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9 + 7;
// constexpr long long MOD = 998244353LL;
using ld = long double;
static const ld pi = 3.141592653589793L;
template <class T> inline void print(T x) { cout << x << '\n'; }
template <class T> bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}
long long gcd(long long x, long long y) { return y ? gcd(y, x % y) : x; }
long long lcm(long long x, long long y) { return x / gcd(x,y)*y ;}
// ~~~~~~~~~~~~~~memo~~~~~~~~~~~~~~
// for (int i = 0; i < n; ++i)
// cout << res << endl;
// cout << res << '\n';
// int型の2次元配列(h×w要素の)の宣言
// vector<vector<int>> data(h, vector<int>(w));
// rotate(s.begin(), s.begin() + 1, s.end());
// sort(all(a),greater<int>());
// s.substr(0,2) 先頭から2文字切り出す
// for (auto it = mp.rbegin();it != mp.rend(); ++it)
// Sparse Table
template<class MeetSemiLattice> struct SparseTable {
    vector<vector<MeetSemiLattice> > dat;
    vector<int> height;
    
    SparseTable() { }
    SparseTable(const vector<MeetSemiLattice> &vec) { init(vec); }
    void init(const vector<MeetSemiLattice> &vec) {
        int n = (int)vec.size(), h = 0;
        while ((1<<h) < n) ++h;
        dat.assign(h, vector<MeetSemiLattice>(1<<h));
        height.assign(n+1, 0);
        for (int i = 2; i <= n; i++) height[i] = height[i>>1]+1;
        for (int i = 0; i < n; ++i) dat[0][i] = vec[i];
        for (int i = 1; i < h; ++i)
            for (int j = 0; j < n; ++j)
                dat[i][j] = min(dat[i-1][j], dat[i-1][min(j+(1<<(i-1)),n-1)]);
    }
    
    MeetSemiLattice get(int a, int b) {
        return min(dat[height[b-a]][a], dat[height[b-a]][b-(1<<height[b-a])]);
    }
};


// Suffix Array ( Manber&Myers: O(n (logn)^2) )
struct SuffixArray {
    string str;
    vector<int> sa;         // sa[i] : the starting index of the i-th smallest suffix (i = 0, 1, ..., n)
    vector<int> lcp;        // lcp[i]: the lcp of sa[i] and sa[i+1] (i = 0, 1, ..., n-1)
    inline int& operator [] (int i) {return sa[i];}
    
    SuffixArray(const string& str_) : str(str_) { buildSA(); calcLCP(); }
    void init(const string& str_) { str = str_; buildSA(); calcLCP(); }
    
    // build SA
    vector<int> rank_sa, tmp_rank_sa;
    struct CompareSA {
        int n, k;
        const vector<int> &rank;
        CompareSA(int n, int k, const vector<int> &rank_sa) : n(n), k(k), rank(rank_sa) {}
        bool operator()(int i, int j) {
            if (rank[i] != rank[j]) return (rank[i] < rank[j]);
            else {
                int rank_ik = (i + k <= n ? rank[i + k] : -1);
                int rank_jk = (j + k <= n ? rank[j + k] : -1);
                return (rank_ik < rank_jk);
            }
        }
    };
    void buildSA() {
        int n = (int)str.size();
        sa.resize(n+1), lcp.resize(n+1), rank_sa.resize(n+1), tmp_rank_sa.resize(n+1);
        for (int i = 0; i < n; ++i) sa[i] = i, rank_sa[i] = (int)str[i];
        sa[n] = n, rank_sa[n] = -1;
        for (int k = 1; k <= n; k *= 2) {
            CompareSA csa(n, k, rank_sa);
            sort(sa.begin(), sa.end(), csa);
            tmp_rank_sa[sa[0]] = 0;
            for (int i = 1; i <= n; ++i) {
                tmp_rank_sa[sa[i]] = tmp_rank_sa[sa[i - 1]];
                if (csa(sa[i - 1], sa[i])) ++tmp_rank_sa[sa[i]];
            }
            for (int i = 0; i <= n; ++i) rank_sa[i] = tmp_rank_sa[i];
        }
    }
    vector<int> rsa;
    SparseTable<int> st;
    void calcLCP() {
        int n = (int)str.size();
        rsa.resize(n+1);
        for (int i = 0; i <= n; ++i) rsa[sa[i]] = i;
        lcp.resize(n+1);
        lcp[0] = 0;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int pi = sa[rsa[i] - 1];
            if (cur > 0) --cur;
            for (; pi + cur < n && i + cur < n; ++cur) {
                if (str[pi + cur] != str[i + cur]) break;
            }
            lcp[rsa[i] - 1] = cur;
        }
        st.init(lcp);
    }
    
    // calc lcp
    int getLCP(int a, int b) {          // lcp of str.sutstr(a) and str.substr(b)
        return st.get(min(rsa[a], rsa[b]), max(rsa[a], rsa[b]));
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    string S;
    cin >> N >> S;

    SuffixArray SA(S);

    int res = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            int lcp = SA.getLCP(i, j);
            lcp = min(lcp, j-i);
            res = max(res, lcp);
        }
    }

    print(res);

    return 0;
}
