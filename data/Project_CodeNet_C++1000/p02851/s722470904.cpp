#include<iostream>
#include<cstdint>
#include<map>
#include<vector>

int const MAXN = 2e5;
int A[MAXN], sum[MAXN+1];
int N, K;

int main() {
  std::cin >> N >> K;
  for(int i = 0; i < N; ++i) std::cin >> A[i];
  sum[0] = 0;
  for(int i = 0; i < N; ++i) sum[i+1] = (((sum[i]+A[i]-1)%K)+K)%K;
  std::map<int, std::vector<int>> m;
  for(int i = 0; i <= N; ++i) m[sum[i]].push_back(i);
  int64_t ans = 0;
  for(auto x: m) if(x.second.size() > 1){
    std::vector<int>& v = x.second;
    for(int i = 0, j = 1; i < v.size()-1; ++i) {
      if(j <= i) j = i+1;
      while(j < v.size() && v[j]-v[i]<K) ++j;
      ans += (int64_t)j-i-1;
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
