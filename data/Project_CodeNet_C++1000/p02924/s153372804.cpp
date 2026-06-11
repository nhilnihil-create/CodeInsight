#include<iostream>

int main(void){
    long long n, ans;
    std::cin >> n;
    ans = (n - 1) * (1 + (n - 1)) / 2;
    std::cout << ans << std::endl;
    return 0;
}