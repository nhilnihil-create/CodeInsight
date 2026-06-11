#include <iostream>

int main(void){
    long long h, w, ans;
    std::cin >> h >> w;

    if (h == 1 || w == 1){
        ans = 1;
    } else if (h * w % 2 == 0){
        ans = h * w / 2;
    } else {
        ans = h * w / 2 + 1;
    }

    std::cout << ans << std::endl;

    return 0;
}