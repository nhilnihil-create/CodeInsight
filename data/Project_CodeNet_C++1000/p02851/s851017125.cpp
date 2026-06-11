#include <bits/stdc++.h>
int main(){
  int n,k;
  std::cin >> n >> k;
  std::vector<long long>v(n),sum(n + 1);
  for(int i = 0; i < n; i++){
    std::cin >> v[i];
    v[i]--;
  }
  for(int i = 0; i < n; i++)sum[i + 1] = sum[i] + v[i];
  for(int i = 0; i <= n; i++)sum[i] %= k;
  std::map<long long,int>m;
  long long ans = 0;
  for(int i = 0; i <= n; i++){
    if(i >= k)m[sum[i - k]]--;
    ans += m[sum[i]];
    m[sum[i]]++;
  }
  std::cout << ans << std::endl;
  return 0;
}