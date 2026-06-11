#include <bits/stdc++.h>
#include <cstdint>
#include <sys/time.h>

typedef std::int_fast32_t  s32;
typedef std::uint_fast32_t u32;
typedef std::int_fast64_t  s64;
typedef std::uint_fast64_t u64;

typedef std::pair<int, int> P;

int main(void) {

  bool isprime[1000000];
  isprime[0] = isprime[1] = false;
  for(int i = 2; i < 1000000; ++i) {
    isprime[i] = true;
  }
  for(int i = 2; i < 1000; ++i) {
    if( isprime[i] ) {
      for(int j = i + i; j < 1000000; j += i) {
        isprime[j] = false;
      }
    }
  }

  int totalprime[1000000] = {};
  int total = 0;
  for(int i = 0; i < 1000000; ++i) {
    if( isprime[i] ) {
      total += 1;
    }
    totalprime[i] = total;
  }
  
  for(;;) {
    int n;
    std::cin >> n;
    if( n == 0 ) break;

    std::cout << totalprime[n * 2] - totalprime[n] << std::endl;
  }
  
  return 0;
}