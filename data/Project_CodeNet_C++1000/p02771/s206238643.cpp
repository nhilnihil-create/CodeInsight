#include<iostream>

int main(void){
    int a, b, c;
    std::cin >> a >> b >> c;
    int cnt = 0;
    if(a == b) cnt++;
    if(a == c) cnt++;
    if(b == c) cnt++;
    if(cnt == 1) std::cout << "Yes" << std::endl;
    else std::cout << "No" << std::endl;
    return 0;
}

