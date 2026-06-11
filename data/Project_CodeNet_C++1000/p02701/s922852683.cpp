#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

int main(){
  int n;
  std::cin >> n;
  std::vector<std::string> s(n);
  for(int i=0;i<n;i++){
    std::cin >> s[i];
  }
  
  std::sort(s.begin(), s.end());
  s.erase(std::unique(s.begin(), s.end()), s.end());

  std::cout << s.size();
  return 0;
}