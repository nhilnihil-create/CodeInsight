#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

int main(){
  int n,s,d1,d2;
  std::cin >> n;
  std::vector<int> d(n);
  for(int i=0;i<n;i++){
    std::cin >> d[i];
  }
  std::sort(d.begin(),d.end());

  s=d.size()/2;
  d1=d[s]; d2=d[s-1];
  std::cout << d1-d2;
}