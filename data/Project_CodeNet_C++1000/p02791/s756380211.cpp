#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <stdio.h>

int main(void){
  int n;
  std::cin >> n;
  int p,min=n+1,ans=0;
  for(int i=0;i<n;i++){
    std::cin >> p;
    if(min>p){
      ans++;
      min = p;
    }
  }
  std::cout << ans;
  return 0;
}