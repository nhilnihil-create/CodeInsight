#include<iostream>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int const MAXN = 3e5;
int N, f[MAXN], m[MAXN], d[MAXN+1];

int main() {
  std::cin >> N;
  std::fill_n(m, N+1, 0);
  for(int i = 0; i < N; ++i) { int A; std::cin >> A; ++m[A-1]; }
  std::fill_n(d, N+1, 0);
  for(int i = 0; i < N; ++i) ++d[m[i]];

  int64_t sum = 0;
  for(int64_t x = 0; x < N; ++x) {
    sum += x*d[x];
    f[x] = sum/(x+1);
  }
  sum = d[N];
  for(int x = N-1; x >= 0; --x) {
    f[x] += sum;
    sum += d[x];
  }

  int ans = N;
  for(int k = 1; k <= N; ++k) {
    ans = std::min(ans, N/k);
    while(ans > 0 && k > f[ans-1]) --ans;
    std::cout << ans << std::endl;
  }
  return 0;
}
