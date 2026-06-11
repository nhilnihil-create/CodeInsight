#include <bits/stdc++.h>
using namespace std;

#define rp(i, k, n) for (int i = k; i < n; i++)
typedef long long ll;
typedef double ld;

template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7ll;
const double PI=3.14159265358979323846;


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
// 使い方
// SuffixArray SA(string) でSuffix Array生成
// SA.getLCP(i, j)で、i文字目からの接尾辞とj文字目からの接尾辞が先頭何文字目まで一致しているかを取得
// Suffix Array, LCP Array ここまで---------------------------------------------------------------------

int main() {
    int n; string s;
    cin >> n >> s;
    SuffixArray SA(s);
    int res = 0;
    rp(i, 0, n) {
        rp(j, i+1, n) {
            int temp = min(j - i, SA.getLCP(i, j));
            chmax(res, temp);
        }
    }
    cout << res << endl;
    return 0;
}