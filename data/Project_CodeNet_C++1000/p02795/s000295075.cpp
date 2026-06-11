#include <iostream>
#include <vector>

int main(){
    int h, w, n;
    std::cin >> h >> w >> n;

    int max = std::max(h, w), ans = n / max;
    if(0 != n % max){
        ++ans;
    }

    std::cout << ans << std::endl;

    return 0;
}