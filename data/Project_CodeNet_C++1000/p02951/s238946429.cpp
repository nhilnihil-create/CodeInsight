#include<iostream>

int main(void){
    int a, b, c;
    std::cin >> a >> b >> c;
    int res = a - b;
    if(c  < res) std::cout << 0 << std::endl;
    else std::cout << c - res << std::endl;
    return 0;
}