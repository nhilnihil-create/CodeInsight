#include <iostream>

long long int sum(long long int n){
    return n * (n + 1) / 2;
}

int main(){
    int n;
    std::cin >> n;

    std::cout << sum(n) - sum(n / 3) * 3 - sum(n / 5) * 5 + sum(n / 15) * 15 << std::endl;

    return 0;
}