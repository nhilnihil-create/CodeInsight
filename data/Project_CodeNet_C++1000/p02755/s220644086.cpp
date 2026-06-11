#include<iostream>
#include<vector>
#include<string>

int main(){
    int a, b;
    std::cin >> a >> b;
    
    for(int i = 1; i <= 10000; i++){
        int a_val = i * 0.08;
        int b_val = i * 0.10;
        if(a == a_val && b == b_val){
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << -1 << std::endl;
    return 0;
}
