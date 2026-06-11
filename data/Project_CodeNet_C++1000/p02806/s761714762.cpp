#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <queue>
#include <set>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <complex>

int main(){
  long long int N, tmp;
  std::string str_tmp;
  std::vector<std::string> S;
  std::vector<long long int> T;

  scanf("%lld", &N);
  for(long long int i = 0; i < N; i++){
    std::cin >> str_tmp >> tmp;
    S.push_back(str_tmp);
    T.push_back(tmp);
  }
  std::cin >> str_tmp;

  long long int flag = 0;
  long long int ans = 0;
  for(long long int i = 0; i < N; i++){
    if(flag == 1){
      ans += T[i];
    }
    if(S[i] == str_tmp){
      flag = 1;
    }
  }

  std::cerr << "Answer: " << std::endl;
  std::cout << ans << std::endl;

  return 0;
  
}
