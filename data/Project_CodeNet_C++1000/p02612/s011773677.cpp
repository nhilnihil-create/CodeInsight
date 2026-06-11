#include <iostream>

int main(){
  
    int money = 0;
    std::cin >> money;

    money %= 1000;
    
    if(money == 0){
        std::cout << '0' << std::endl;
    }else{
        std::cout << 1000 - money << std::endl;
    }
}