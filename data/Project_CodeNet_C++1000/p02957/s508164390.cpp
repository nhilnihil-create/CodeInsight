#include<iostream>

int main(void){
    int a, b;
    std::cin >> a >> b;
    if((a + b) % 2 != 0) std::cout << "IMPOSSIBLE" << std::endl;
    else std::cout << (a + b) / 2 << std::endl;
    return 0;
}