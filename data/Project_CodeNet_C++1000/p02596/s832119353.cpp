#include<iostream>

int main(void){
    int k;
    std::cin >> k;
    int cur = 7 % k;
    int cnt = 1;
    for(int i = 0; i <= k; i++){
        if(cur == 0){
            std::cout << cnt << std::endl;
            return 0;
        }else{
            cnt++;
            cur = cur * 10 + 7;
            cur %= k;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}