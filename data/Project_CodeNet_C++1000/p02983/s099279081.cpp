#include<iostream>

int main(void){
    int l, r;
    std::cin >> l >> r;
    if(r >= 2019 + l){
        r = 2019 + l;
    }
    int min = 2018;
    for(int i = l; i <= r; i++){
        for(int j = i+1; j <= r; j++){
            int cur = (i % 2019) * (j % 2019);
            cur %= 2019;
            min = std::min(cur, min);
        }
    }
    std::cout << min << std::endl;

    return 0;
}