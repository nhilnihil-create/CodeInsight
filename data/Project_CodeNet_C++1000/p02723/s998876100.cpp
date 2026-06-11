#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <stdio.h>

int main(void){
  std::string s;
  std::cin >> s;
  if(s[2]==s[3] && s[4]==s[5]){
    std::cout << "Yes";
  }else{
    std::cout << "No";
  }
  return 0;
}