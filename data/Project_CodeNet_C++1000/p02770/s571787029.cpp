#include <iostream>
#include<cstdint>

int const MAXK = 5000;

int64_t d[MAXK], dorg[MAXK];
int k, q;

void proc(int64_t n, int64_t x, int64_t m) {
  for(int i = 0; i < k; ++i) d[i] = dorg[i]%m;
  x %= m;
  int64_t ans = n-1; // j in [0, n-2]
  // remove count of: a_j == a_{j+1} (mod m)
  //     1. repeated in [(n-1)%k, n-1)
  int64_t c = 0;
  for(int i = 0; i < k; ++i) if(d[i] == 0) ++c;
  c *= (n-1)/k;
  ans -= c;
  //     2. in [0, (n-1)%k)
  for(int i = 0; i < (n-1)%k; ++i) if(d[i] == 0) --ans;

  // remove count of: a_j >= a_{j+1} (mod m)
  // i.e. count of multiple of m in (x, x+sum d[j%k])
  // i.e. that of (0, x+sum d[j%k]) (because x in [0, m))
  //   calc sum d[j%k]
  //     1. repeated j in [(n-1)%k, n-1)
  int64_t sum = 0;
  for(int i = 0; i < k; ++i) sum += d[i];
  sum *= (n-1)/k;
  //     2. in [0, (n-1)%k)
  for(int i = 0; i < (n-1)%k; ++i) sum += d[i];
  //   remove the count
  ans -= (x + sum)/m;
  std::cout << ans << std::endl;
}

int main() {
  std::cin >> k >> q;
  for(int i = 0; i < k; ++i) std::cin >> dorg[i];
  for(int i = 0; i < q; ++i) {
    int64_t n, x, m; std::cin >> n >> x >> m;
    proc(n, x, m);
  }
}
