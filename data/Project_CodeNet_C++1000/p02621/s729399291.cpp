#include <iostream>
#include <string.h>

int main(){
  
  int a;
  int ans;
  std::cin >> a;
  
  ans = a + a * a + a * a * a; 
  std::cout << ans << std::endl;
    
    return 0;
}