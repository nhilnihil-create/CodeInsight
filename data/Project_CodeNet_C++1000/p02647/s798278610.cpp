#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdlib>
template<typename T>
void fin(std::vector<T>const& t, char delim=' '){
  if(t.size() > 0) {
    for(int i = 0; i < t.size() -1; ++i) std::cout << t[i] << delim;
    std::cout << t.back();
  }
  std::cout << std::endl;
  exit(0);
}

int main() {
  std::cin.tie(0); std::ios::sync_with_stdio(false);
  int N, K; std::cin >> N >> K;
  std::vector<int> A(N), B(N+1);
  for(auto& Ai: A) std::cin >> Ai;

  for(int i = 0; i < K; ++i) {
    std::fill_n(B.begin(), N, 0);
    for(int i = 0; i < N; ++i) {
      int l = std::max(0, i-A[i]), r = std::min(N-1, i+A[i]);
      ++B[l]; --B[r+1];
    }
    for(int i = 1; i < N; ++i) B[i] += B[i-1];
    int cnt = 0;
    for(auto& Bi: B) if(Bi == N) ++cnt;
    if(cnt == N) break;
    std::copy_n(B.begin(), N, A.begin());
  }
  B.pop_back();
  fin(B);
  return 0;
}
