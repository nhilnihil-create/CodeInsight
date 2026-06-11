#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

int main(){
  std::string n;
  std::cin >> n;
  for(int i=0;i<n.size();i++){
    if(n[i]=='7'){
      std::cout << "Yes";
      exit(0);
    }
  }
  std::cout << "No";
  return 0;
}