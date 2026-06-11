#include<iostream>

int main(void){
    long long w, h, x, y;
    std::pair<double, double> c;
    std::cin >> w >> h >> x >> y;
    c = std::make_pair(w / 2.0, h / 2.0);
    double ans = h * w / 2.0;
    std::cout << ans << " ";
    if(x == w / 2.0 && y == h / 2.0) std::cout << 1 << std::endl;
    else std::cout << 0 << std::endl;
    return 0;
}