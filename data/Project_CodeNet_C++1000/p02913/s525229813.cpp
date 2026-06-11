#include<iostream>
#include<string>
#include<algorithm>
#include<cstdint>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int N;
std::string S;

int check(int l) {
  int res = 0, tmp = 0;
  for(int i = 0; i < N-l; ++i) {
    if(S[i] == S[i+l]) ++tmp;
    else { res = std::max(res, tmp); tmp = 0; }
  }
  return std::max(res, tmp);
}

int main() {
   std::cin >> N >> S;
  int ans = 0;
  for(int l = N/2; l > ans; --l) {
    ans = std::max(ans, std::min(l, check(l)));
    if(l != N-l) ans = std::max(ans, check(N-l));
  }
  fin(ans);
  return 0;
}
