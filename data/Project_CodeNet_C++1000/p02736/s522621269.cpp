#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int64_t fact_log2(int64_t n) {
  int64_t res = 0;
  while(n/=2) res += n;
  return res;
}

int64_t mod2_comb(int64_t n, int64_t k) {
  if(n < 0 || k < 0 || n < k) return 0;
  int64_t e1 = fact_log2(n);
  int64_t e2 = fact_log2(k);
  int64_t e3 = fact_log2(n-k);
  if(e1 > e2+e3) return 0;
  return 1;
}

int main() {
  int N; std::cin >> N;
  int p[5] = {2, 1, 0, 1, 2};
  std::vector<int> a(N);
  char pc; std::cin >> pc; --N;
  for(int i = 0; i < N; ++i) {
    char c; std::cin >> c;
    a[i] = p[pc - c + 2];
    pc = c;
  }
  int b = 0;
  for(int i = 0; i < N; ++i) if(mod2_comb(N-1, i)) b ^= (a[i]&1);
  if(b==1) fin(1); // odd
  for(int i = 0; i < N; ++i) if(a[i]==1) fin(0);
  for(int i = 0; i < N; ++i) if(mod2_comb(N-1, i)) b ^= (a[i]&2);
  if(b==2) fin(2);
  fin(0);
  return 0;
}
