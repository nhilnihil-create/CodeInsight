// suffix array
#include <bits/stdc++.h>
using namespace std;
// Sparse Table
template<class Monoid> struct SparseTable {
    vector<vector<Monoid> > data;
    vector<int> height;
    
    SparseTable() {}
    SparseTable(const vector<Monoid> &vec) { init(vec); }
    void init(const vector<Monoid> &vec) {
        int n = (int)vec.size(), h = 0;
        while ((1<<h) < n) h++; // 1<<h >= n

        height.assign(n+1, 0);
        for (int i = 2; i <= n; i++) height[i] = height[i>>1]+1; // 2進数での桁数 - 1

        data.assign(h, vector<Monoid>(n));
        for (int i = 0; i < n; i++) data[0][i] = vec[i];
        for (int i = 1; i < h; i++)
            for (int j = 0; j < n; j++)
                data[i][j] = min(data[i-1][j], data[i-1][min(j+(1<<(i-1)),n-1)]);
    }
    
    Monoid get(int a, int b) {
        return min(data[height[b-a]][a], data[height[b-a]][b-(1<<height[b-a])]);
    } // [a,b) 0-indexed
};

// Suffix Array
struct SuffixArray {
    string str;
    vector<int> sa; // the starting index of the i-th smallest suffix (i = 0 ~ n)
    vector<int> lcp; // the lcp(longest common prefix array) of sa[i] and sa[i+1] (i = 0 ~ n-1)
    
    SuffixArray() {}
    SuffixArray(const string &str_) : str(str_) { buildSA(); calcLCP(); }
    void init(const string &str_) { str = str_; buildSA(); calcLCP(); }
    
    // build suffix array
    vector<int> rank, tmp_rank;
    void buildSA() {
        int n = (int)str.size();
        sa.resize(n+1), rank.resize(n+1), tmp_rank.resize(n+1);

        for (int i = 0; i < n; i++) sa[i] = i, rank[i] = str[i] - 'a';
        sa[n] = n, rank[n] = -1;

        for (int k = 1; k <= n; k *= 2) {
            auto comp = [&](int i, int j) {
                if (rank[i] != rank[j]) return rank[i] < rank[j];
                int rank_ik = (i+k <= n ? rank[i+k] : -1);
                int rank_jk = (j+k <= n ? rank[j+k] : -1);
                return rank_ik < rank_jk;
            };
            sort(sa.begin(), sa.end(), comp);
            tmp_rank[sa[0]] = 0;
            for (int i = 1; i <= n; i++) {
                tmp_rank[sa[i]] = tmp_rank[sa[i-1]];
                if (comp(sa[i-1], sa[i])) tmp_rank[sa[i]]++;
            }
            rank = tmp_rank;
        }
    }

    // calculate lcp
    vector<int> rsa;
    SparseTable<int> st; // lcp配列をのせる
    void calcLCP() {
        int n = (int)str.size();
        lcp.resize(n), rsa.resize(n+1);
        for (int i = 0; i <= n; i++) rsa[sa[i]] = i;
        int count = 0;
        for (int i = 0; i < n; i++) {
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
  
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      int ch = SA.getLCP(i,j);
      ans = max(ans,min(ch,j-i));
    }
  }
  cout << ans << endl;
  return 0;
}