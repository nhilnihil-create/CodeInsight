#include<iostream>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

// bit
#include<functional>
template<typename T, int NN>
struct bit {
  typedef std::function<T(T,T)> OP;
  T data_[NN], e_; // 0-base
  OP& op_;
  bit(OP& op, T e) : op_(op), e_(e) { std::fill_n(data_, NN, e_); }
  int lb(int i){ return i&-i; }
  T query(int i) { // 1-base
    T res = e_;
    while(i > 0) { res = op_(res, data_[i-1]); i -= lb(i); }
    return res;
  } 
  void add(int i, T const& v) { // 1-base
    while(i <= NN) { data_[i-1] = op_(data_[i-1], v); i += lb(i); }
  }
};

int const MAXN = 300;
int const MAXNN = 1<<9;
int64_t const INF = 1e18;
int64_t H[MAXN+1], Hs[MAXN+1], tos[MAXN+1], N, K;
int64_t dp[MAXN+1][MAXN+1];

int main() {
  std::cin >> N >> K;
  int pH = 0;
  H[0] = 0;
  for(int i = 1; i <= N; ++i) std::cin >> H[i];
  // dp[i][j]: i = #choosen, j = <last choice>; j >= i
  // dp[i][j] = min{ dp[i-1][k] + max(0, H[j]-H[k]) | k in [1,j) }
  //          = min( dp[i-1][k] where H[j] <= H[k],
  //                 dp[i-1][k] + H[j] - H[k] where H[j] > H[k] )
  //          = min( min{ dp[i-1][k] | H[j] <= H[k] },
  //                  min{ dp[i-1][k] - H[k] | H[j] > H[k] } + H[j] )
  // Hs[] := uniq(sort(H[])), tos[] s.t. Hs[tos[i]] = H[i]
  // H[j] < H[k] <=> tos[j] < tos[k]
  // ans = min { dp[N-K][j] | j in [1,N] }
  //
  // 
  std::copy_n(H+1, N, Hs+1);
  std::sort(Hs+1, Hs+1+N);
  int m = std::unique(Hs+1, Hs+1+N) - Hs;
  for(int i = 1; i <= N; ++i) {
    tos[i] = std::partition_point(Hs, Hs+m, [&](int j){ return j < H[i]; }) - Hs;
  }
  std::copy_n(H+1, N, dp[1]+1);
  for(int i = 2; i <= N-K; ++i) {
    std::fill_n(dp[i], N+1, INF);
    bit<int64_t, MAXNN>::OP op = [](int64_t x, int64_t y){ return std::min(x, y); };
    bit<int64_t, MAXNN> b1(op, INF), b2(op, INF);
    for(int j = i-1; j <= N; ++j) {
      if(j >= i) {
        dp[i][j] = std::min(b1.query(m-tos[j]), b2.query(tos[j]) + H[j]);
      }
      b1.add(m-tos[j], dp[i-1][j]);
      b2.add(tos[j], dp[i-1][j] - H[j]);
    }
  }
  int64_t ans = INF;
  for(int j = N-K; j <= N; ++j) ans = std::min(ans, dp[N-K][j]);
  fin(ans);
  return 0;
}
