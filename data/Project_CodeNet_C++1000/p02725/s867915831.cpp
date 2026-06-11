#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <stdio.h>

int main(void){
  int k,n,out=0;
  std::cin >> k >> n;
  std::vector<int> a(n);
  std::vector<int> s(n);
  for(int i=0;i<n;i++){
    std::cin >> a[i];
  }
  for(int i=0;i<n-1;i++){
    s[i] = a[i+1] - a[i];
  }
  s[n-1] = a[0] + k - a[n-1];
  std::sort (s.begin(),s.end());
  for(int i=0;i<n-1;i++){
    out = out + s[i];
  }
  std::cout << out;
  return 0;
}