#include<iostream>
#include<vector>
#include<string>

int main(){
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int cnt_a = (c + b - 1) / b;
    int cnt_b = (a + d - 1) / d;
    if(cnt_a <= cnt_b){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
    return 0;
}
