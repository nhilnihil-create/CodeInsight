#include<iostream>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int const MAXN = 2e5;
int N;
int64_t A[MAXN], F[MAXN], K;

bool isOK(int64_t th) {
  int64_t sum = 0;
  for(int i = 0; i < N; ++i) {
    int64_t a = A[i], f = F[N-1-i];
    if(a*f <= th) continue;
    int64_t newa = th/f;
    sum += (a - newa);
    if(sum > K) return false;
  }
  return true;
}

int main() {
  std::cin >> N >> K;
  for(int i = 0; i < N; ++i) std::cin >> A[i];
  for(int i = 0; i < N; ++i) std::cin >> F[i];
  std::sort(A, A+N);
  std::sort(F, F+N);
  int64_t ng = -1, ok = 0;
  for(int i = 0; i < N; ++i) ok = std::max(ok, A[i]*F[N-1-i]);
  while(ok - ng > 1) {
    int64_t mid = (ok+ng)/2;
    if(isOK(mid)) ok = mid; else ng = mid;
  }
  fin(ok);
  return 0;
}
