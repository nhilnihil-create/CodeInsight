#include<bits/stdc++.h>

const long long mod = 1e9 + 7;

int main(){
  int n; std::cin >> n;
  if(n < 3){
    std::cout << 0;
    return 0;
  }
  std::vector<long long> arr (n+1); arr[0] = 1;
  for(int i = 0; i <= n; ++i){
    if(arr[i] == 0) continue;
    for(int num = 3; i+num <= n; ++num){
      arr[i+num] += arr[i];
      arr[i+num] %= mod;
    }
  }
  std::cout << arr[n];
}