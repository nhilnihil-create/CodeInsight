#include <iostream>

int main(){
    int x, y;
    std::cin >> x >> y;

    int ans = 0;
    ans += 100000 * (std::max(0, 4 - x));
    ans += 100000 * (std::max(0, 4 - y));

    if(1 == x * y){
        ans += 400000;
    }

    std::cout << ans << std::endl;

    return 0;
}