#include<iostream>
#include<cstdint>

int64_t T1, T2, V1, V2;

int main() {
  int64_t A1, A2, B1, B2; std::cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
  V1 = A1-B1; V2 = A2-B2;
  if(V1 < 0) { V1 = -V1; V2 = -V2; }
  int64_t dm = V1*T1, d = dm + V2*T2;
  if(d > 0) { std::cout << "0" << std::endl; return 0; }
  if(d == 0) { std::cout << "infinity" << std::endl; return 0; }
  int64_t ans = 1;
  int64_t r = (dm-1)/(-d);
  ans += r*2;
  if(dm%(-d)==0) ++ans;
  std::cout << ans << std::endl;
  return 0;
}
