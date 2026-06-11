#include<iostream>

int main(void){
    int n, l;
    std::cin >> n >> l;
    int sum = n * (l - 1) + (n + 1) * n / 2;
    if(l > 0) std::cout << sum - l << std::endl;
    else if(l + n - 1 < 0) std::cout << sum - (l + n - 1) << std::endl;
    else std::cout << sum << std::endl;
    return 0;
}