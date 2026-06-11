#include <iostream>

int circle(int r){
    return r*r;
}

int main(){ 
    int r, ans;
    std::cin >> r;

    ans = circle(r);

    std::cout << ans;
    return 0;
}