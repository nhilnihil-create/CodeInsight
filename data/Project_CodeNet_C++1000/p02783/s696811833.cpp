#include<iostream>

int main(void){
    int h, a;
    std::cin >> h >> a;
    int ans = h / a;
    if(h % a != 0) ans++;
    std::cout << ans << std::endl;
    return 0;
}

