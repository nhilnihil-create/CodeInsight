#include<iostream>

int main(void){
    int a, b;
    std::cin >> a >> b;
    if(b * 2 >= a){
        std::cout << 0 << std::endl;
    }else{
        std::cout << a - b * 2 << std::endl;
    }

    return 0;
}