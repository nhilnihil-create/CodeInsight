#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdio.h>

int main(void){
  std::string t;
  std::cin >> t;

  replace(t.begin(), t.end(), '?', 'D');

  std::cout << t;
  return 0;
}