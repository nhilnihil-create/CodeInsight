#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

int main(){
  int n=0;
  std::string s,t;
  std::cin >> s >> t;

  for(int i=0;i<3;i++){
    if(s[i]==t[i]){
      n++;
    }
  }
  
  std::cout << n;
}