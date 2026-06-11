#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int X;
  
  cin >> X;
  
  long long int out = 100;
  int year = 0;
  while (out < X){
    out += out / 100;
    // std::cout << out <<std::endl;
  
    year += 1;
  }
  std::cout << year <<std::endl;
  
}
