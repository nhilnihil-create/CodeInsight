#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

// Sparse Table
template<class Monoid> struct SparseTable {
    vector<vector<Monoid> > data;
    vector<int> height;
    
    SparseTable() {}
    SparseTable(const vector<Monoid> &vec) { init(vec); }
    void init(const vector<Monoid> &vec) {
        int n = (int)vec.size();
        int h = 0; while ((1<<h) < n) h++;

        height.assign(n+1, 0);
        rep(i,n+1) if(i >= 2) height[i] = height[i>>1]+1;

        data.assign(h, vector<Monoid>(n));
        rep(i,n) data[0][i] = vec[i];
        rep(i,h) if(i) rep(j,n) data[i][j] = min(data[i-1][j], data[i-1][min(j+(1<<(i-1)),n-1)]);
    }
    
    Monoid get(int a, int b) {
        int k = height[b-a];
        return min(data[k][a], data[k][b-(1<<k)]);
    } // [a,b) 0-indexed
};

// Suffix Array
struct SuffixArray {
    string str;
    int n;
    vector<int> sa; // the starting index of the i-th smallest suffix (i = 0 ~ n)
    vector<int> lcp; // the lcp(longest common prefix array) of sa[i] and sa[i+1] (i = 0 ~ n-1)
    
    SuffixArray() {}
    SuffixArray(const string &str_) { str = str_; n = (int)str.length(); buildSA(); calcLCP(); }
    void init(const string &str_) { str = str_; n = (int)str.length(); buildSA(); calcLCP(); }
    
    // build suffix array
    vector<int> rank, tmp_rank;
    void buildSA() {
        sa.resize(n+1), rank.resize(n+1), tmp_rank.resize(n+1);

        rep(i,n) sa[i] = i, rank[i] = str[i] - 'a';
        sa[n] = n, rank[n] = -1;

        int k = 1;
        while (k <= n) {
            auto comp = [&](int i, int j) {
                if (rank[i] != rank[j]) return rank[i] < rank[j];
                return (i+k <= n ? rank[i+k] : -1) < (j+k <= n ? rank[j+k] : -1);
            };
            sort(sa.begin(), sa.end(), comp);
            tmp_rank[sa[0]] = 0;
            rep(i,n+1) if(i) {
                tmp_rank[sa[i]] = tmp_rank[sa[i-1]];
                if (comp(sa[i-1], sa[i])) tmp_rank[sa[i]]++;
            }
            rank = tmp_rank;
            k <<= 1;
        }
    }

    // calculate lcp
    vector<int> rsa;
    SparseTable<int> st;
    void calcLCP() {
        lcp.resize(n), rsa.resize(n+1);
        rep(i,n+1) rsa[sa[i]] = i;

        int count = 0;
        rep(i,n) {
            int pi = sa[rsa[i] - 1];
            if (count > 0) count--;
            while(i + count < n && pi + count < n){
                if (str[pi + count] != str[i + count]) break;
                count++;
            }
            lcp[rsa[i] - 1] = count;
        }
        st.init(lcp);
    }
    
    int getLCP(int a, int b) {
        a = rsa[a]; b = rsa[b]; if(a > b) swap(a,b);
        return st.get(a,b);
    } // s[a:] と s[b:] のlcp
};

int main() {
    int n; string s; cin >> n >> s;
    SuffixArray SA(s);
  
    int ans = 0;  
    rep(i,n) rep(j,n) if(i < j) ans = max(ans,min(SA.getLCP(i,j),j-i));
    cout << ans << endl;
    return 0;
}