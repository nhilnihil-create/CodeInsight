#include <bits/stdc++.h>
using Int = int64_t;

const Int N = 312345;
bool is_prime[N];

int main() {
   for(Int i = 0; i < N; ++i) {
      is_prime[i] = true;
   }
   is_prime[0] = is_prime[1] = false;
   for(Int i = 2; i * i < N; ++i) {
      if( is_prime[i] ) {
         for(Int k = 2*i; k < N; k+=i) {
            is_prime[k] = false;
         }
      }
   }
   for(;;) {
      Int n;
      std::cin >> n;
      if( n == 0 ) break;
      Int count = 0;
      for(Int i = n+1; i <= 2*n; ++i) {
         if( is_prime[i] ) {
            count += 1;
         }
      }
      std::cout << count << std::endl;
   }
}


