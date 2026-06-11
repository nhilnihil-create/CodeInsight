#include<iostream>

int main(void){
    int n, h;
    std::cin >> n;
    std::cin >> h;
    int b = h;
    for(int i = 1; i < n; i++){
        std::cin >> h;
        if(b > h){
            std::cout << "No" << std::endl;
            return 0;
        }else if(b <= h - 1){
            h--;
        }
        b = h;
    }
    std::cout << "Yes" << std::endl;
    return 0;
}