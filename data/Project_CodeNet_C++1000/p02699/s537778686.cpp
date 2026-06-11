#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

int main(){
  int s,w;
  std::cin >> s >> w;
  if(s>w){
    std::cout << "safe";
  }else{
    std::cout << "unsafe";
  }
  
  return 0;
}