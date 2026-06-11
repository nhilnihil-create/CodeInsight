#include <iostream>

int main(void){
    int a, b, quo, rem, ans;
    std::cin >> a >> b;
    quo = (b-1) / (a-1);
    rem = (b-1) % (a-1);

    ans = quo;
    if (rem != 0) ++ans;

    std::cout << ans << std::endl; 

    return 0;
}