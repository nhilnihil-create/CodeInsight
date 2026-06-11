#include <iostream>
#include <cmath>

bool is_prime(int n){
  bool flag = true;
  if(n % 2 == 0) flag = false;
  for(int i=3; i <= sqrt(n); i+=2){
    if(n % i == 0){
      flag = false;
      break;
    }
  }
  if(n == 2) flag = true;
  return flag;
}

int main(void){
  int n;
  while(1){
    int cnt = 0;
    std::cin >> n;
    if(n == 0)  return 0;
    for(int i = n+1; i <= 2*n; i++){
      if(is_prime(i)){
      cnt++;
      }
    }
    std::cout << cnt << std::endl;
  }
}