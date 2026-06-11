#include<iostream>
#include<vector>
int main(){
  int n;
  std::cin >> n;
  std::vector<int> cnt(n), sum(n);
  for(int i = 0; i < n; ++i){
    int a;
    std::cin >> a;
    ++sum[cnt[a - 1]++];
  }
  int it = n, acc = n;
  for(int t = 1; t <= n; ++t){
    while(acc < it * t)
      acc -= sum[--it];
    std::cout << it << std::endl;
  }
}