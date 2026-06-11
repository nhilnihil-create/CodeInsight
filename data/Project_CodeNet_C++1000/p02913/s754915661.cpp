// Range Minimum Query: LCP用
#include<functional>
#include<vector>
template<typename T> class SparseTable {
 public:
  explicit SparseTable(const std::vector<T>& v, const std::function<bool(T, T)>& F = std::less<T>()) : V(v), F(F), table_(v.size()) {
    for(auto i = 0; i < v.size(); ++i) table_[0].emplace_back(i);
    for(auto i = 1; pow2(i) <= v.size(); ++i) {
      for(auto j = 0; j + pow2(i) - 1 < v.size(); ++j) {
        auto a = table_[i - 1][j + pow2(i - 1)];
        auto b = table_[i - 1][j];
        table_[i].emplace_back(F(v[a], v[b]) ? a : b);
      }
    }
  }
  T index(int l, int r) const {
    auto d = leftmost(r - l + 1);
    auto a = table_[d][r - pow2(d) + 1];
    auto b = table_[d][l];
    return F(V[a], V[b]) ? a : b;
  }
  T find(int l, int r) const {
    return V[index(l, r)];
  }
 private:
  inline int pow2(int n) const {return 1 << n;}
  inline int leftmost(int n) const {return std::__lg(n);}
  const std::vector<T> V;
  const std::function<bool(T, T)> F;
  std::vector<std::vector<int>> table_;
};

template<typename T> using RangeMinimumQuery = SparseTable<T>;

// Suffix Array
#include<algorithm>
#include<memory>
#include<numeric>
#include<string>
#include<vector>

class SuffixArray {
 public:
  explicit SuffixArray(const std::string& S) : S(S), N(S.size()), sa_(N + 1), rank_(N + 1), lcp_(N + 1) {init();}
  std::vector<int> suffix_array() const {return sa_;}
  std::vector<int> rank() const {return rank_;}
  std::vector<int> lcp_array() const {return lcp_;}
  int longest_common_prefix(int i, int j) const {
    if(rank_[i] > rank_[j]) std::swap(i, j);
    return rmq_->find(rank_[i], rank_[j] - 1);
  }

 private:
  void init() {
    init_sa();    // essential
    init_lcp();   // optional
  }
  // Manber-Myers: O(N log^2 N)
  void init_sa() {
    int k;
    auto less = [N = N, &rank = rank_, &k](auto i, auto j) {
      if(rank[i] != rank[j]) return rank[i] < rank[j];
      if(N < j + k) return false;
      if(N < i + k) return true;
      return rank[i + k] < rank[j + k];
    };
    std::iota(std::begin(sa_), std::end(sa_), 0);
    for(int i = 0; i <= N; ++i) rank_[i] = i < N ? S[i] : -1;
    for(k = 1; k <= N; k *= 2) {
      std::sort(std::begin(sa_), std::end(sa_), less);
      auto tmp = rank_;
      tmp[sa_[0]] = 0;
      for(int i = 1; i <= N; ++i) tmp[sa_[i]] = tmp[sa_[i - 1]] + (less(sa_[i - 1], sa_[i]) ? 1 : 0);
      rank_ = tmp;
    }
  }
  // O(N + RMQ構築)
  void init_lcp() {
    int h = 0;
    lcp_[0] = 0;
    for(int i = 0; i < N; ++i) {
      auto j = sa_[rank_[i] - 1];
      for(h = std::max(0, h - 1); j + h < N && i + h < N; ++h) if(S[j + h] != S[i + h]) break;
      lcp_[rank_[i] - 1] = h;
    }
    rmq_ = std::make_unique<RangeMinimumQuery<int>>(lcp_);
  }
  const std::string S;
  const int N;
  std::vector<int> sa_, rank_, lcp_;
  std::unique_ptr<RangeMinimumQuery<int>> rmq_;
};

#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  SuffixArray sa(S);

  auto ans = 0;
  for(auto i=0; i<N; ++i) for(auto j=i+1; j<N; ++j) {
    auto k = sa.longest_common_prefix(i, j);
    auto len = min(k, j - i);
    ans = max(ans, len);
  }
  cout << ans << endl;
}
