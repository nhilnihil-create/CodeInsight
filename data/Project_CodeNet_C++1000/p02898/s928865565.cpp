#include<iostream>

int main(void){
    int n, k;
    std::cin >> n >> k;
    int h;
    int ans = 0;
    for(int i = 0; i < n; i++){
        std::cin >> h;
        if(h >= k) ans++;
    }
    std::cout << ans << std::endl;

    return 0;
}