#include <iostream>

int main(void){
    int X, C, ans=0;
    std::cin >> X;
    C = X / 100;
    if (X >= C * 100 && X <= C * 105) ans = 1;

    std::cout << ans << std::endl;

    return 0;
}
