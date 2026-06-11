#include<iostream>
#include<algorithm>
#include<cstdlib>
template<typename T>
void fin(T const& t){ std::cout << t << std::endl; exit(0); }

int main() {
  int N, K; std::cin >> N >> K;
  int Mx = N*(N-1)/2, Mt = Mx - (N-1);
  if(K > Mt) fin(-1);
  int ans = Mx - K;

  // gen
  std::cout << ans << "\n";
  for(int i = 2; i <= N; ++i) {
    std::cout << "1 " << i << "\n";
    --ans;
  }

  if(ans) for(int i = 2; i < N; ++i) for(int j = i+1; j <= N; ++j) {
    std::cout << i << " " << j << "\n";
    if(--ans == 0) return 0;
  }
  return 0;
}
