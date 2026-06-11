#include<iostream>

int main(){
    unsigned long long int a;
    double b;
    
    std::cin >> a >> b;

    int bb = b * 100 + 0.5;
    unsigned long long int ans = a * bb / 100;
    std::cout << ans << std::endl;

    return 0;
}