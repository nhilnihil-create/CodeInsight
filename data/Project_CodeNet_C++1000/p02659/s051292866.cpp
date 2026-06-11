#include<iostream>

int main(void){
    long long a;
    double b;
    std::cin >> a >> b;
    long long bint = b * 100 + 0.5;
    long long ans;

    ans = a * bint / 100;

    std::cout << ans << std::endl;

    return 0;
}
