#include<iostream>
#include<iomanip>

int main(void){
    int n;
    std::cin >> n;
    int oddc = (n + 1) / 2;
    std::cout << std::fixed << std::setprecision(15) << double(oddc) / n << std::endl;
    return 0;
}