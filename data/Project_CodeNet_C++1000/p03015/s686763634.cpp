#include<iostream>
#include<string>

int const MOD = 1e9+7;
int const MAXLL = 1e5+2;
std::string L;

int n, p3;

int calc_p3(int x) {
  for(; n < x; ++n) {
    int t = (p3 + p3)%MOD;
    (p3 += t) %= MOD;
  }
  return p3;
}

int main() {
  n = 0; p3 = 1;
  std::cin >> L;
  int ans = 1, l = L.size(), d = 0;
  while(--l >= 0) {
    if(L[l] == '1') {
      int t = (ans + calc_p3(d))%MOD;
      (ans += t) %= MOD;
    }
    ++d;
  }
  std::cout << ans << std::endl;
  return 0;
}
