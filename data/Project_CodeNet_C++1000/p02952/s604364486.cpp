#include<iostream>

int seekKeta(int n){
    int keta = 0;
    while(n != 0){
        n /= 10;
        keta++;
    }
    return keta;
}

int main(void){
    int n;
    std::cin >> n;
    int keta = seekKeta(n);
    int maxketa;
    int ans = 0;
    if(keta % 2 == 0){
        maxketa = keta - 1;
    }else{
        maxketa = keta - 2;
    }
    int cur = 9;
    for(int i = 1; i <= maxketa; i+=2){
        ans += cur;
        cur *= 100;
    }
    int res = 1;
    for(int i = 0; i < keta-1; i++){
        res *= 10;
    }
    if(keta % 2 == 1){
        ans += n - res + 1;
    }

    std::cout << ans << std::endl;
    return 0;
}