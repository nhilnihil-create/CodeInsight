#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;


void solve(long long N, std::vector<long long> H){
  ll x = H[0];
  ll ans = 0;
  ll cnt = 0;
  for(int i=1; i<N; i++) {
    if(x < H[i]) {
      ans = max(ans, cnt);
      cnt = 0;
    } else {
      cnt++;
    }
    x = H[i];
  }
  ans = max(ans, cnt);
  std::cout << ans << std::endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> H(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&H[i]);
    }
    solve(N, std::move(H));
    return 0;
}
