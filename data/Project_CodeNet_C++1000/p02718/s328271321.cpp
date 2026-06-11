#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <numeric>
#include <algorithm>
#include <stdio.h>

int main(void){
  double n,m,s=0;
  std::cin >> n >> m;
  std::vector<double> a(n);
  for(int i=0;i<n;i++){
    std::cin >> a[i];
  }
  
  for(int i=0;i<n;i++){
    s += a[i];
  }
  std::sort(a.begin(),a.end());
  std::reverse(a.begin(),a.end());
  
  if((a[m-1])>=s/(4.0*m)){
    std::cout << "Yes";
  }else{
    std::cout << "No";
  }
  
  return 0;
}