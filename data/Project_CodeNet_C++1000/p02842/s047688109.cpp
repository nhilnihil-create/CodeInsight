#include <iostream>
#include <vector>
int main(){
  int n, a, b;
  std::cin >> n;
  if (floor(ceil(n / 1.08) * 1.08) == n){
  	std::cout << ceil(n / 1.08) << std::endl;
  }else{
  	std::cout << ":(" << std::endl;
  }
}