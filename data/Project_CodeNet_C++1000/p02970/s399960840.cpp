#include<iostream>

int main(void){
    int n, d;
    std::cin >> n >> d;
    int c = d * 2 + 1;
    int ans = n / c;
    if(n % c != 0) ans++;
    std::cout << ans << std::endl;
    return 0;
}