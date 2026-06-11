#include<iostream>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

uint64_t getZ() {
  uint64_t v = 0; int c;
  while((c = getchar_unlocked()) >= '0') v=v*10+c-'0';
  return v;
}

int const MAXN = 2e5;
int64_t A[MAXN];
int N;
int main() {
  N = getZ();
  int64_t vx = 0, vo = 0;
  for(int i = 0; i < N; ++i) { A[i] = getZ(); vx ^= A[i]; vo |= A[i]; }
  int64_t vc = vo - vx, vd = 0;
  for(int i = 0, j = 0; i < 60 && j < N; ++i) {
    int64_t b = (int64_t)1 << 59-i;
    if(!(b&vc)) continue;
    if(!(A[j]&b)) {
      for(int k = j+1; k < N; ++k) if(A[k]&b) {
        std::swap(A[j], A[k]); break;
      }
    }
    if(!(A[j]&b)) continue;
    for(int k = j+1; k < N; ++k) if(A[k]&b) A[k] ^= A[j];
    if(!(vd&b)) vd ^= A[j];
    ++j;
  }
  vd &= vc;
  fin(vd*2+vx);
  return 0;
}
