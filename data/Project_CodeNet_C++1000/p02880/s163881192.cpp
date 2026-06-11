#include<iostream>

int main(void){
    int n;
    std::cin >> n;
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            if(n == i * j){
                std::cout << "Yes" << std::endl;
                return 0;
            }
        }
    }
    std::cout << "No" << std::endl;
    return 0;
}