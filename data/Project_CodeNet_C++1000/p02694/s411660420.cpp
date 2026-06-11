#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>

int main(){
  long long a=100,i,x;
  std::cin >> x;
  for(i=0;a<x;i++){
    a=a+a/100;
  }
  std::cout << i;
}