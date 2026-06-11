#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

int main(){
  std::string s;
  std::cin >> s;

  if(s=="Sunny"){
    std::cout << "Cloudy";
  }else if(s=="Cloudy"){
    std::cout << "Rainy";
  }else{
    std::cout << "Sunny";
  }
}