#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>

int main(void){
  int n,k,d,at;
  std::vector<int> a;
  std::cin >> n >> k;
  for(int c=0;c<k;c++){
    std::cin >> d;
    for(int i=0;i<d;i++){
      std::cin >> at;
      auto itr = std::find(a.begin(), a.end(), at); 
      if(itr == a.end()){
        a.push_back(at);
      }
    }
  }
  int c=0;
  for(int i=1;i<=n;i++){
    auto itr = std::find(a.begin(), a.end(), i); 
    if(itr == a.end()){
      c++;
    }
  }
  std::cout << c;
  return 0;
}