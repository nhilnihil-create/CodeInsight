#include<iostream>

int main(void){
    int a, b;
    std::cin >> a >> b;
    a--;
    int ans;
    ans = (b - 1) / a;
    if((b - 1) % a != 0) ans++;
    std::cout << ans << std::endl;
    return 0;
}