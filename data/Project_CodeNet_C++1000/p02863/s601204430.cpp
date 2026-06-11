#include<iostream>
#include<algorithm>
#include<numeric>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int const MAXN = 3000;
int const MAXT = 3000;

int A[MAXN], B[MAXN], ix[MAXN];
int N, T;

int dp[MAXN-1][MAXT];

int main() {
  std::cin >> N >> T;
  for(int i = 0; i < N; ++i) std::cin >> A[i] >> B[i];
  std::iota(ix, ix+N, 0);
  std::sort(ix, ix+N, [&](int l, int r){ return A[l] < A[r]; });
  
  std::fill_n(dp[0], T, B[ix[0]]);
  std::fill_n(dp[0], A[ix[0]], 0);
  for(int i = 1; i < N-1; ++i) {
    // doesn't choose dish ix[i]
    std::copy_n(dp[i-1], T, dp[i]);
    // choose dish i;
    for(int j = A[ix[i]]; j < T; ++j) {
      dp[i][j] = std::max(dp[i][j], dp[i-1][j-A[ix[i]]] + B[ix[i]]);
    }
  }
  int ans = 0;
  for(int i = 0; i < N-1; ++i) {
    int cur = 0;
    for(int j = i+1; j < N; ++j) cur = std::max(cur, B[ix[j]]);
    ans = std::max(ans, cur + dp[i][T-1]);
  }
  fin(ans);
  return 0;
}
