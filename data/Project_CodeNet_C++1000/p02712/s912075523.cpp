#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

int main(){
  long long n,s=0;
  std::cin >> n;
  for(int i=1;i<=n;i++){
    if(i%3!=0&&i%5!=0){
      s+=i;
    }
  }
  std::cout << s;
  return 0;
}