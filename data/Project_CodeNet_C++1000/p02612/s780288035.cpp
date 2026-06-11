#include <iostream>

int main(){
  
    int money = 0;
    std::cin >> money;
  
    while(money > 1000){
        money -= 1000;
    }
  
    std::cout << 1000 - money << std::endl;
}