#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

int main(){
  int ain,as,n;
  std::cin >> n;
  std::vector<int> a(n,0);
  for(int i=1;i<n;i++){
    std::cin >> ain;
    a[ain-1]++;
  }
  as=a.size();
  for(int i=0;i<as;i++){
    std::cout << a[i] << std::endl;
  }
  
  return 0;
}