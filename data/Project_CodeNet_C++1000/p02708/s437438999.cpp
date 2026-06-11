#include <iostream>

typedef long long ll;

const int MAX_N = 2e5;
const ll MOD = 1e9 + 7;

ll S(ll n, ll a, ll l){
   return n * (a + l) / 2;
}

int main(){
   int N, K;
   std::cin >> N >> K;

   ll ans = 0;
   for(int k=K; k<=N+1; ++k){
      ans +=  S(k, N-k, N+1) - S(k, 0, k-1) + 1;
      ans %= MOD;
   }
   std::cout << ans << std::endl;

   return 0;
}
