#include<iostream>
int main(){
    int k,x; std::cin >> k >> x;
    std::cout << (k*500 < x ? "No" : "Yes") << std::endl;
    return 0;
}