#include <iostream>
typedef long long ll;
typedef long double ld;

int main(){
  ll x;std::cin >> x;
  ld now = 100, eps = 1e-6;
  ll ans = 0;

  while(now + eps < x){
    ll add = now/100;
    now += add;
    ans++;
  }
  std::cout << ans << '\n';
  return 0;
}
